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


static void		print_env(const t_heap *heap, size_t j)
{
	t_node *n;

	n = (t_node *)heap->list[j];
	if (n->key && n->value)
		ft_printf("%s=%s\n", n->key, n->value);
}

int has_error(char ar[2])
{
	if (ft_strchr(ar, 'i') && ft_strchr(ar, 'u'))
		return 1;
	return 0;
}

/*
** List all environments variables
** Take no arguments
*/

int				b_env(char **args, t_shell *shell)
{
	t_hashtable		*temp;
	int				part_args;

	part_args = 1;
	temp = clone_hashtable(g_shell.env);
	while (*args)
	{
		if (part_args && ft_strstarts_with_str(*args, "-") && ft_strlen(*args) == 2)
		{
			if ((*args)[1] == 'u')
			{
				args++;
				if (*args)
				{    /*remove *args from hashtable*/}
				else return 0;
			}
			else if ((*args)[1] == 'i')
			{
				{    /*remove all from hashtable*/}
				part_args = 0;
				continue;
			}
		}
		else if (ft_strstr(*args, "="))
		{
			char **toks = strsplit_first(*args, "=");
			if (toks && size_tab(toks) == 2)
			{
				ht_set(temp, toks[0], ft_strdup(toks[1]));
				free_tab(toks);
			}
		}
		else {

		}

		args++;
	}
	return (1);
}
/**
arg_part = 1;
while str
 	if (arg_part && str is an arg as x)
 		if (x == "u")
 			next as u
 			remove u from temp hashtable
 		if (x == "i")
 			remove all from hashtable
 			arg_part = 0
 	if (is assignation)
 		res = splitfirst at = on str
 		add res[0] as key and res[1] as value to hashtable
 	else
 		y = get rest of str as string
 		g_shell.temp_env = hashtable
 		execute_shell(y, 1)
 		break

