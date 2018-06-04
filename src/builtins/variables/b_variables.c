/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_variables.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/04 09:12:21 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/04 09:12:21 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void		print_variables(const t_heap *heap, size_t j)
{
	t_node	*n;
	t_var	*var;

	n = (t_node *)heap->list[j];
	if (n->key && n->value)
	{
		var = n->value;
		ft_printf("%s=%s\n", var->symbol, var->value);
	}
}

/*
** List all variables that are not exported
** Take no arguments
*/

int				b_variables(char **args, t_shell *shell)
{
	t_heap	*heap;
	size_t	i;
	size_t	j;

	(void)shell;
	i = 0;
	(void)args;
	while (i < g_shell.vars->size)
	{
		heap = g_shell.vars->heaps[i];
		j = 0;
		while (heap && heap->elements > 0 && j < heap->size)
		{
			if (heap->list[j])
				print_variables(heap, j);
			j++;
		}
		i++;
	}
	return (1);
}
