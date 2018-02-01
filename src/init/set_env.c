/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_env.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 10:35:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 18:36:06 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

extern char	**environ;

/*
** Retrieve all paths from environ and add it to a hashtable
*/

void	set_env(void)
{
	int		i;
	char	**splitted;
	char	*tmp;

	g_shell.env = ht_new(128);
	g_shell.env_trie = trie_new();
	i = -1;
	while (environ[++i])
	{
		splitted = ft_strsplit(environ[i], '=');
		if (splitted && splitted[0] && splitted[1])
		{
			tmp = ft_strjoin(ft_char_to_str('$'), splitted[0]);
			ft_printf(" - %s\n", tmp);
			ht_set(g_shell.env, splitted[0], ft_strdup(splitted[1]));
			trie_insert(g_shell.env_trie, tmp);
			free(tmp);
			tmp = NULL;
		}
		free_tab(splitted);
	}
}
