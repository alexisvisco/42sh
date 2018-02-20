/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bundle_funcs_0.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 21:06:41 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 21:06:41 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

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