/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_base.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:16:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:16:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

static t_expr	*te_tok_open(t_state *s)
{
	t_expr *ret;
	next_token(s);
	ret = list(s);
	if (s->type != TOK_CLOSE)
		s->type = TOK_ERROR;
	else
		next_token(s);
	return (ret);
}

static t_expr	*te_error(t_state *s, t_expr *ret)
{
	ret = new_expr(0, 0);
	s->type = TOK_ERROR;
	ret->value = NAN;
	return (ret);
}

static t_expr	*te_tok_var(const t_state *s, t_expr *ret)
{
	ret = new_expr(TE_VARIABLE, 0);
	ret->bound = s->bound;
	next_token(s);
	return (ret);
}

t_expr			*base(t_state *s)
{
	t_expr	*ret;
	int		arity;

	if (TYPE_MASK(s->type) == TOK_NUMBER)
	{
		ret = new_expr(TE_CONSTANT, 0);
		ret->value = s->value;
		next_token(s);
	}
	else if (TYPE_MASK(s->type) == TOK_VARIABLE)
		ret = te_tok_var(s, ret);
	else if (TYPE_MASK(s->type) == TE_CLOSURE0)
		ret = te_clos0(s, ret);
	else if (TYPE_MASK(s->type) == TE_CLOSURE1)
		ret = te_clos1(s, ret);
	else if (TYPE_MASK(s->type) == TOK_OPEN)
		ret = te_tok_open(s);
	else if (TYPE_MASK(s->type) == TE_CLOSURE7)
		ret = te_clos7(s, ret, arity);
	else
		ret = te_error(s, ret);
	return (ret);
}


