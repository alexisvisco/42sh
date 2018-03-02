/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_variable.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 14:00:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 14:00:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	free_variable(void *var)
{
	t_var *variables;

	variables = (t_var *)var;
	if (variables->value)
		free(variables->value);
	free(variables);
}

void	free_node_variable(void *var)
{
	t_node *node;

	node = var;
	free(node->value);
	if (node->value)
		free_variable(node);
	free(node);
}