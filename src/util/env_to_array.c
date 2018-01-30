/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env_to_array.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 09:51:44 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 14:36:03 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	put_in_array(char **env, int *k)
{
	t_hashtable	*t;
	size_t		i;
	size_t		j;
	char		*str;
	
	i = 0;
	t = g_shell.env;
	while (i < t->size)
	{
		if (t->heaps[i])
		{
			j = 0;
			while (j < t->heaps[i]->size)
			{
				if (t->heaps[i]->list[j])
				{
					str = ft_sprintf("%s=%s",
					((t_node *)t->heaps[i]->list[j])->key,
					(char *)((t_node *)t->heaps[i]->list[j])->value);
					env[(*k)] = str;
					(*k)++;
				}
				j++;
			}
		}
		i++;
	}
}

size_t		env_size()
{
	t_hashtable	*t;
	size_t		i;
	size_t		size;
	
	i = 0;
	t = g_shell.env;
	size = 0;
	while (i < t->size)
	{
		if (t->heaps[i])
			size += t->heaps[i]->elements;
		i++;
	}
	return (size);
}

char		**env_to_array(void)
{
	t_hashtable	*envs;
	char		**env;
	size_t		size;
	int			k;
	

	envs = g_shell.env;
	size = env_size();
	env = (char **)malloc((size + 1) * sizeof(char *));
	env[size] = 0;
	k = 0;
	put_in_array(env, &k);
	return (env);
}
