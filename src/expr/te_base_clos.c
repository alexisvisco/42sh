/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_base_clos.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:39:18 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:39:18 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

t_expr		*te_clos0(t_state *s, t_expr *ret)
{
	ret = new_expr(s->type, 0);
	ret->function = s->function;
	if (IS_CLOSURE(s->type))
		ret->parameters[0] = s->context;
	next_token(s);
	if (s->type == TOK_OPEN)
	{
		next_token(s);
		if (s->type != TOK_CLOSE)
			s->type = TOK_ERROR;
		else
			next_token(s);
	}
	return (ret);
}

t_expr		*te_clos1(const t_state *s, t_expr *ret)
{
	ret = new_expr(s->type, 0);
	ret->function = s->function;
	if (IS_CLOSURE(s->type))
		ret->parameters[1] = s->context;
	next_token(s);
	ret->parameters[0] = power(s);
	return (ret);
}

static void	te_clos7_annex(const t_state *s, t_expr **ret, int *arity)
{
	(*arity) = ARITY(s->type);
	(*ret) = new_expr(s->type, 0);
	(*ret)->function = s->function;
}

t_expr		*te_clos7(t_state *s, t_expr *ret, int arity)
{
	int i;

	te_clos7_annex(s, &ret, &arity);
	if (IS_CLOSURE(s->type))
		ret->parameters[arity] = s->context;
	next_token(s);
	if (s->type != TOK_OPEN)
		s->type = TOK_ERROR;
	else
	{
		i = -1;
		while (++i < arity)
		{
			next_token(s);
			ret->parameters[i] = expr(s);
			if (s->type != TOK_SEP)
				break ;
		}
		if (s->type != TOK_CLOSE || i != arity - 1)
			s->type = TOK_ERROR;
		else
			next_token(s);
	}
	return (ret);
}