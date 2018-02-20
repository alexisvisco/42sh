/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_expr.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:50:42 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:50:42 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "expr.h"

t_expr	*expr(t_state *s)
{
	t_expr *ret;

	ret = term(s);
	while (s->type == TOK_INFIX && (s->function == add || s->function == sub))
	{
		t_fun2 t = s->function;
		next_token(s);
		ret = NEW_EXPR(TE_FUNCTION2 | TE_FLAG_PURE, ret, term(s));
		ret->function = t;
	}
	return (ret);
}