/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   replace_env_variables.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/13 10:05:13 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:33 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void		replace_with(t_node *n, char **str)
{
	char *key;
	char *tmp;

	tmp = *str;
	key = ft_strjoin("$", n->key);
	*str = ft_repall(key, n->value, *str);
	free(tmp);
	free(key);
}

/*
** Replace env variables in a string to the value
** i need to be -1
** The return value is ALWAYS allocated on the heap.
*/

char			*replace_env_variables(char *str, int free_str)
{
	char	*xstr;
	t_heap	*heap;
	size_t	i;
	size_t	j;

	i = 0;
	xstr = ft_strdup(str);
	while (i < g_shell.env->size)
	{
		heap = g_shell.env->heaps[i];
		j = 0;
		while (heap && heap->elements > 0 && j < heap->size)
		{
			if (heap->list[j])
				replace_with(((t_node *)heap->list[j]), &xstr);
			j++;
		}
		i++;
	}
	if (free_str)
		free(str);
	return (xstr);
}
