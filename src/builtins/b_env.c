/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_env.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

#define IS_ARGS (ftn & 1<<0 && ft_strstarts_with_str(*args, "-"))

static void		print(t_hashtable *t)
{
	t_heap	*heap;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < t->size)
	{
		heap = t->heaps[i];
		j = 0;
		while (heap && heap->elements > 0 && j < heap->size)
		{
			if (heap->list[j])
			{
				ft_printf("%s=%s\n", ((t_node *)heap->list[j])->key,
						  ((t_node *)heap->list[j])->value);
			}
			j++;
		}
		i++;
	}
}

static int		exec_args(int *ftn, char ***args, t_hashtable **temp)
{
	t_node *d;

	if ((*(*args))[1] == 'u')
	{
		(*args)++;
		if (**args)
		{
			d = ht_remove(*temp, **args);
			free_node(&d);
		}
		else
			return (1);
	}
	else if ((*(*args))[1] == 'i')
	{
		*ftn = 0 << 0;
		ht_free((*temp));
		(*temp) = ht_new(128);
	}
	return (0);
}

static void		exec_assign(char **args, t_hashtable *temp)
{
	char **toks;

	toks = strsplit_first(*args, "=");
	if (toks && toks[0][0] != 0 && toks[1][0] != 0)
	{
		ht_set(temp, toks[0], ft_strdup(toks[1]));
	}
	free_tab(toks);
}

static void		end(t_hashtable *temp, int ftn)
{
	if (!(ftn & 1 << 2))
		print(temp);
	ht_free(temp);
}

/*
** Set environment and execute command, or print environment
**
** PART_ARGS  = 1 << 0
** EXIT_ERROR = 1 << 1
** CAN_PRINT  = 1 << 2
*/

int				b_env(char **args, t_shell *shell)
{
	t_hashtable		*temp;
	int				ftn;

	(void)shell;
	ftn = 1 << 0;
	temp = clone_hashtable(g_shell.env);
	args++;
	while (*args)
	{
		if (IS_ARGS && ft_strlen(*args) == 2)
		{
			if ((ftn |= exec_args(&ftn, &args, &temp) << 1) & 1 << 1)
				return (0);
		}
		else if (ft_strstr(*args, "="))
			exec_assign(args, temp);
		else
		{
			ftn |= execute_env_cmd(args, temp) << 2;
			break ;
		}
		args++;
	}
	end(temp, ftn);
	return (1);
}
