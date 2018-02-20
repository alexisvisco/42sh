/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_factor.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:47:10 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:47:10 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

t_expr *factor(t_state *s)
{
	t_expr *ret;

	ret = power(s);
	while (s->type == TOK_INFIX && (s->function == math_pow))
	{
		t_fun2 t = s->function;
		next_token(s);
		ret = NEW_EXPR(TE_FUNCTION2 | TE_FLAG_PURE, ret, power(s));
		ret->function = t;
	}
	return (ret);
}
