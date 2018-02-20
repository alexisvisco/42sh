/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_power.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:45:30 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:45:30 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "expr.h"

static t_expr *power(t_state *s)
{
	int		sign;
	t_expr	*ret;

	sign = 1;
	while (s->type == TOK_INFIX && (s->function == add || s->function == sub))
	{
		if (s->function == sub)
			sign = -sign;
		next_token(s);
	}
	if (sign == 1)
		ret = base(s);
	else
	{
		ret = NEW_EXPR(TE_FUNCTION1 | TE_FLAG_PURE, base(s));
		ret->function = negate;
	}
	return (ret);
}