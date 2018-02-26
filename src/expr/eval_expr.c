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

#include "expr.h"

int g_stack[4096] = {0};
int g_idx = 0;
int g_ustack[4096] = {0};

static int	get_bool(t_priority p, char **s, int **a, int *i)
{
	return (p == MULTIPLICATIVE && multiplicative(s, &p, a, i)) ||
	(p == ADDITIVE && additive(s, &p, a, i)) ||
	(p == SHIFT && shift(s, &p, a, i)) ||
	(p == RELATIONAL && relational(s, &p, a, i)) ||
	(p == EQUALITY && equality(s, &p, a, i)) ||
	(p == AND && andex(s, &p, a, i)) ||
	(p == XOR && xorex(s, &p, a, i)) ||
	(p == OR && orex(s, &p, a, i)) ||
	(p == LAND && land(s, &p, a, i)) ||
	(p == LOR && lor(s, &p, a, i)) ||
	(p == CONDITIONAL && conditionalex(s, a, i)) ||
	(p == ASSIGN && assignex(s, &p, a)) ||
	(p == EXPR && exprex(s, &p, a));
}

int			*eval(char **s, t_priority p)
{
	int	*a;
	int	*i;

	a = NULL;
	if (p == PRIMARY)
		return (primary(s, a));
	if (p == UNARY)
		return (unary(s, &p, a));
	a = eval(s, p - 1);
	i = g_stack + g_idx;
	while (42)
	{
		if (ISWS(**s))
			++*s;
		else if (**s == '\0' || (get_bool(p, s, &a, i)))
			return (a);
	}
}

int			eval_expr(char *str)
{
	return (*(eval(&str, MAX)));
}
