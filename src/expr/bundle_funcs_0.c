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

#define RET_PRIMARY (a = eval((++*s, s), MAX)), ++*s, a
#define UNARY1 (*a = -GET_NEXT), a
#define UNARY2 eval((++*s, s), (*p) - 1)
#define UNARY3 (*a = ~GET_NEXT), a
#define UNARY4 (*a = !GET_NEXT), a
#define UNARY5 (*a = ++*eval((*s += 2, s), (*p) - 1)), a
#define UNARY6 (*a = --*eval((*s += 2, s), (*p) - 1)), a
#define MUL1 ((*i = **a * GET_NEXT), i)
#define MUL2 ((*i = **a / GET_NEXT), i)
#define MUL3 ((*i = **a % GET_NEXT), i)
#define SHIFT1 ((*i = **a << *eval((*s += 2, s), (*p) - 1)), i)
#define SHIFT2 ((*i = **a >> *eval((*s += 2, s), (*p) - 1)), i)
#define ADD1 ((*i = **a - GET_NEXT), i)
#define ADD2 ((*i = **a + GET_NEXT), i)

int		*primary(char **s, int *a)
{
	int i;

	while (ISWS(**s))
		++*s;
	if (**s == '(')
		return (RET_PRIMARY);
	if (**s == '$')
	{
		i = 0;
		++*s;
		while (ft_isdigit(**s))
			i = i * 10 + *(*s)++ - '0';
		return (g_ustack + i);
	}
	a = g_stack + g_idx++;
	*a = 0;
	while (ft_isdigit(**s))
		*a = *a * 10 + *(*s)++ - '0';
	return (a);
}

int		*unary(char **s, t_priority *p, int *a)
{
	a = g_stack + g_idx;
	while (ISWS(**s))
		++*s;
	if (**s == '-' && OPEND(*(*s + 1)))
		return (UNARY1);
	if (**s == '+' && OPEND(*(*s + 1)))
		return (UNARY2);
	if (**s == '~' && OPEND(*(*s + 1)))
		return (UNARY3);
	if (**s == '!' && OPEND(*(*s + 1)))
		return (UNARY4);
	if (**s == '+' && *(*s + 1) == '+' && OPEND(*(*s + 2)))
		return (UNARY5);
	if (**s == '-' && *(*s + 1) == '-' && OPEND(*(*s + 2)))
		return (UNARY6);
	return (eval(s, (*p) - 1));
}

int		multiplicative(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '*' && OPEND(*(*s + 1)))
		*a = MUL1;
	else if ((**s == '/' || **s == '%') && GET_NEXT == 0)
		**a = 0;
	else if (**s == '/' && OPEND(*(*s + 1))) {
        deb_printer("Hello world !!!!\n");
        *a = MUL2;
    }
	else if (**s == '%' && OPEND(*(*s + 1)))
		*a = MUL3;
	else
		return (1);
	return (0);
}

int		additive(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '-' && OPEND(*(*s + 1)))
		*a = ADD1;
	else if (**s == '+' && OPEND(*(*s + 1)))
		*a = ADD2;
	else
		return (1);
	return (0);
}

int		shift(char **s, t_priority *p, int **a, int *i)
{
	if (**s == '<' && *(*s + 1) == '<' && OPEND(*(*s + 2)))
		*a = SHIFT1;
	else if (**s == '>' && *(*s + 1) == '>' && OPEND(*(*s + 2)))
		*a = SHIFT2;
	else
		return (1);
	return (0);
}
