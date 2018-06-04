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

	if (var)
	{
		variables = (t_var *)var;
		ft_memdel((void **)&(variables->value));
	}
	ft_memdel((void **)&var);
}

void	free_node_variable(void *var)
{
	t_node *node;

	node = var;
	if (node)
	{
		ft_memdel((void **)&(node->key));
		if (node->value)
			free_variable(node->value);
		ft_memdel((void **)&node);
	}
}
