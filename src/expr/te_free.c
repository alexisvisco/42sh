/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_free_parameters.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 13:29:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:29:56 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

void	te_free_parameters(t_expr *n)
{
	if (!n)
		return;
	if (TYPE_MASK(n->type) == TE_CLOSURE7)
		te_free(n->parameters[6]);
	else if (TYPE_MASK(n->type) == TE_CLOSURE6)
		te_free(n->parameters[5]);
	else if (TYPE_MASK(n->type) == TE_CLOSURE5)
		te_free(n->parameters[4]);
	else if (TYPE_MASK(n->type) == TE_CLOSURE4)
		te_free(n->parameters[3]);
	else if (TYPE_MASK(n->type) == TE_CLOSURE3)
		te_free(n->parameters[2]);
	else if (TYPE_MASK(n->type) == TE_CLOSURE2)
		te_free(n->parameters[1]);
	else if (TYPE_MASK(n->type) == TE_CLOSURE1)
		te_free(n->parameters[0]);
}

void	te_free(t_expr *n)
{
	if (!n)
		return;
	te_free_parameters(n);
	free(n);
}
