/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_list.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:44:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:44:00 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "expr.h"

t_expr	*list(t_state *s)
{
	t_expr *ret;

	ret = expr(s);
	while (s->type == TOK_SEP)
	{
		next_token(s);
		ret = NEW_EXPR(TE_FUNCTION2 | TE_FLAG_PURE, ret, expr(s));
		ret->function = comma;
	}
	return (ret);
}
