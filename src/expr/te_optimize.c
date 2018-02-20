/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_optimize.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 14:51:47 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 14:51:47 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

static void	opt_ext(t_expr *n, double value)
{
	value = te_eval(n);
	te_free_parameters(n);
	n->type = TE_CONSTANT;
	n->value = value;
}

static void	optimize(t_expr *n)
{
	int		arity;
	double	value;
	int		known;
	int		i;

	if (n->type == TE_CONSTANT)
		return;
	if (n->type == TE_VARIABLE)
		return;
	if (IS_PURE(n->type))
	{
		arity = ARITY(n->type);
		known = 1;
		i = -1;
		while (++i < arity)
		{
			optimize(n->parameters[i]);
			if (((t_expr *) (n->parameters[i]))->type != TE_CONSTANT)
				known = 0;
		}
		if (known)
			opt_ext(n, value);
	}
}