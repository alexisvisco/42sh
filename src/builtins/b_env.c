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

#define IS_ASSIGN(str) ft_strstr(str, "=")

static char *concat_array(char **t)
{
	size_t s;
	int    x;
	char   *total;

	s     = 0;
	x     = -1;
	while (t[++x])
		s += ft_strlen(t[x]) + 1;
	total = ft_memalloc(s);
	x     = -1;
	while (t[++x])
	{
		ft_strcat(total, t[x]);
		ft_strcat(total, " ");
	}
	return total;
}

static void		free_node(t_node **d)
{
	if (d)
	{
		ft_memdel((void **) &((*d)->key));
		ft_memdel(&((*d)->value));
		ft_memdel((void **) &(*d));
	}
}

static int		exec_args(int *part_args, char ***args, t_hashtable **temp)
{
	t_node *d;

	if (*part_args && ft_strstarts_with_str(*(*args), "-") &&
		ft_strlen(*(*args)) == 2)
	{
		if ((*(*args))[1] == 'u')
		{
			(*args)++;
			if (*(++(*args)))
			{
				d = ht_remove((*temp), *(*args));
				free_node(&d);
			}
			else
				return (-1);
		}
		else if ((*(*args))[1] == 'i')
		{
			*part_args = 0;
			ht_free((*temp));
			(*temp) = ht_new(128);
		}
		return (1);
	}
	return (0);
}

static void exec_assign(char **args, t_hashtable *temp)
{
	char **toks = strsplit_first(*args, "=");
	if (toks && toks[0][0] != 0 && toks[1][0] != 0)
	{
		ht_set(temp, toks[0], ft_strdup(toks[1]));
		free_tab(toks);
	}
}

int execute_cmd(char **args)
{
	char *to_execute;

	int is_cmd;
	is_cmd     = 1;
	to_execute = concat_array(args);
	ft_memdel((void **) &(g_shell.line));
	ft_printf("Excution for %s\n", to_execute);
	return is_cmd;
}

/*
** List all environments variables
** Take no arguments
*/

int b_env(char **args, t_shell *shell)
{
	t_hashtable *temp;
	int         part_args;
	int         is_cmd;
	int 		res;

	(void) shell;
	part_args = 1;
	is_cmd    = 0;
	temp      = clone_hashtable(g_shell.env);
	args++;
	while (*args)
	{
		if ((res = exec_args(&part_args, &args, &temp)) <= 0)
		{
			if (res == -1)
				return 0;
		}
		else if (ft_strstr(*args, "="))
			exec_assign(args, temp);
		else
		{
			is_cmd = execute_cmd(args);
			break;
		}
		args++;
	}
	if (!is_cmd)
		ht_print(temp, ht_print_str);
	ht_free(temp);
	return (1);
}


