/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   env_to_array.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 11:45:37 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 11:50:23 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void	put_in_array(char **env, int *k)
{
	t_hashtable	*t;
	size_t		i;
	int64_t		j;
	char		*str;

	i = 0;
	t = g_shell.env;
	while (i < t->size)
	{
		if (t->heaps[i])
		{
			j = -1;
			while (++j < (int64_t)t->heaps[i]->size)
			{
				if (t->heaps[i]->list[j])
				{
					str = ft_sprintf("%s=%s", ((t_node *)
t->heaps[i]->list[j])->key, (char *)((t_node *)t->heaps[i]->list[j])->value);
					ft_printf("%s %lu\n", str, *k);
					env[(*k)++] = str;
				}
			}
		}
		i++;
	}
}

size_t		env_size(void)
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
	ft_printf("size: %lu\n", size);
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
