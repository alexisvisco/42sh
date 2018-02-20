/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_expr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:38:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 10:14:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <f_is.h>
#include "expr.h"


int g_stack[4096]  = {0};
int g_idx          = 0;
int g_ustack[4096] = {0};

#define ISWS(c) ((c) == ' ' || ((c) >= '\t' && (c) <= '\r'))
#define OPEND(c) (ft_isdigit(c) || ISWS(c) || (c) == '$')

int *primary(char **s, int *a)
{
	int i;

	while (ISWS(**s)) ++*s;
	if (**s == '(')
		return (a = eval((++*s, s), MAX)), ++*s, a;
	if (**s == '$')
	{
		i = 0;
		++*s;
		while (ft_isdigit(**s))
			i = i * 10 + *(*s)++ - '0';
		return g_ustack + i;
	}
	a             = g_stack + g_idx++;
	*a     = 0;
	while (ft_isdigit(**s))
		*a = *a * 10 + *(*s)++ - '0';
	return a;
}

int *unary(char **s, t_priority *p, int *a)
{
	a = g_stack + g_idx;
	while (ISWS(**s)) ++*s;
	if (**s == '-' && OPEND(*(*s + 1)))
		return (*a = -*eval((++*s, s), (*p) - 1)), a;
	if (**s == '+' && OPEND(*(*s + 1)))
		return eval((++*s, s), (*p) - 1);
	if (**s == '~' && OPEND(*(*s + 1)))
		return (*a = ~*eval((++*s, s), (*p) - 1)), a;
	if (**s == '!' && OPEND(*(*s + 1)))
		return (*a = !*eval((++*s, s), (*p) - 1)), a;
	if (**s == '+' && *(*s + 1) == '+' && OPEND(*(*s + 2)))
		return (*a = ++*eval((*s += 2, s), (*p) - 1)), a;
	if (**s == '-' && *(*s + 1) == '-' && OPEND(*(*s + 2)))
		return (*a = --*eval((*s += 2, s), (*p) - 1)), a;
	return (eval(s, (*p) - 1));
}

int multiplicative(char **s, t_priority *p, int **a, int *i)
{

	if (**s == '*' && OPEND(*(*s + 1)))
		*a = ((*i = **a * *eval((++*s, s), (*p) - 1)), i);
	else if (**s == '/' && OPEND(*(*s + 1)))
		*a = ((*i = **a / *eval((++*s, s), (*p) - 1)), i);
	else if (**s == '%' && OPEND(*(*s + 1)))
		*a = ((*i = **a % *eval((++*s, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int additive(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '-' && OPEND(*(*s + 1)))
		*a = ((*i = **a - *eval((++*s, s), (*p) - 1)), i);
	else if (**s == '+' && OPEND(*(*s + 1)))
		*a = ((*i = **a + *eval((++*s, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int shift(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '<' && *(*s + 1) == '<' && OPEND(*(*s + 2)))
		*a = ((*i = **a << *eval((*s += 2, s), (*p) - 1)), i);
	else if (**s == '>' && *(*s + 1) == '>' && OPEND(*(*s + 2)))
		*a = ((*i = **a >> *eval((*s += 2, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int relational(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '<' && OPEND(*(*s + 1)))
		*a = ((*i = **a < *eval((++*s, s), (*p) - 1)), i);
	else if (**s == '>' && OPEND(*(*s + 1)))
		*a = ((*i = **a > *eval((++*s, s), (*p) - 1)), i);
	else if (**s == '<' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = ((*i = **a <= *eval((*s += 2, s), (*p) - 1)), i);
	else if (**s == '>' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = ((*i = **a >= *eval((*s += 2, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int equality(char **s, t_priority *p, int **a, int *i)
{

	if (**s == '=' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = ((*i = **a == *eval((*s += 2, s), (*p) - 1)), i);
	else if (**s == '!' && *(*s + 1) == '=' && OPEND(*(*s + 2)))
		*a = ((*i = **a != *eval((*s += 2, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int andex(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '&' && OPEND(*(*s + 1)))
		*a = ((*i = **a & *eval((++*s, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int xorex(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '^' && OPEND(*(*s + 1)))
		*a = ((*i = **a ^ *eval((++*s, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int orex(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '|' && OPEND(*(*s + 1)))
		*a = ((*i = **a | *eval((++*s, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int land(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '&' && *(*s + 1) == '&' && OPEND(*(*s + 2)))
		*a = ((*i = **a && *eval((*s += 2, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int lor(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '|' && *(*s + 1) == '|' && OPEND(*(*s + 2)))
		*a = ((*i = **a || *eval((*s += 2, s), (*p) - 1)), i);
	else
		return (1);
	return (0);
}

int conditionalex(char **s, int **a, int *i)
{
	int *b;
	int *c;

	if (**s == '?' && *(*s + 1) == ':' && OPEND(*(*s + 2)))
	{
		b = eval((*s += 2, s), MAX);
		*a = ((*i = **a ? **a : *b), i);
	}
	else if (**s == '?' && OPEND(*(*s + 1)))
	{
		b = eval((++*s, s), MAX);
		while (ISWS(**s))
			++*s;
		c = eval((++*s, s), MAX);
		*a = ((*i = **a ? *b : *c), i);
	}
	else
		return (1);
	return (0);
}

int assignex(char **s, t_priority *p, int **a)
{
	if (**s == '=' && OPEND(*(*s + 1)))
		**a = *eval((++*s, s), (*p) - 1);
	else
		return (1);
	return (0);
}

int exprex(char **s, t_priority *p, int **a)
{
	if (**s == ',' && OPEND(*(*s + 1)))
		*a = eval((++*s, s), (*p) - 1);
	else
		return (1);
	return (0);
}

int *eval(char **s, t_priority p)
{
	int *a;
	int *i;

	a = NULL;
	if (p == PRIMARY)
		return (primary(s, a));
	if (p == UNARY)
		return (unary(s, &p, a));
	a = eval(s, p - 1);
	i = g_stack + g_idx;
	while (1)
	{
		if (ISWS(**s))
			++*s;
		else if (**s == '\0' ||
			(p == MULTIPLICATIVE && multiplicative(s, &p, &a, i)) ||
			(p == ADDITIVE && additive(s, &p, &a, i)) ||
			(p == SHIFT && shift(s, &p, &a, i)) ||
			(p == RELATIONAL && relational(s, &p, &a, i)) ||
			(p == EQUALITY && equality(s, &p, &a, i)) ||
			(p == AND && andex(s, &p, &a, i)) ||
			(p == XOR && xorex(s, &p, &a, i)) ||
			(p == OR && orex(s, &p, &a, i)) ||
			(p == LAND && land(s, &p, &a, i)) ||
			(p == LOR && lor(s, &p, &a, i)) ||
			(p == CONDITIONAL && conditionalex(s, &a, i)) ||
			(p == ASSIGN && assignex(s, &p, &a)) ||
			(p == EXPR &&  exprex(s, &p, &a)))
			return (a);
	}
}

int eval_expr(char *str)
{
	return *(eval(&str, MAX));
}