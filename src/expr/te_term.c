/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_term.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:49:24 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:49:24 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

t_expr *term(t_state *s)
{
	t_expr *ret;

	ret = factor(s);
	while (s->type == TOK_INFIX &&
	(s->function == mul || s->function == divide || s->function == fmodt))
	{
		t_fun2 t = s->function;
		next_token(s);
		ret = NEW_EXPR(TE_FUNCTION2 | TE_FLAG_PURE, ret, factor(s));
		ret->function = t;
	}
	return (ret);
}