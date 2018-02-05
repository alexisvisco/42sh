/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_env.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 10:35:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 11:49:31 by aviscogl    ###    #+. /#+    ###.fr     */
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
	char	*c;

	g_shell.env = ht_new(128);
	g_shell.env_trie = trie_new();
	i = -1;
	while (environ[++i])
	{
		splitted = ft_strsplit(environ[i], '=');
		if (splitted && splitted[0] && splitted[1])
		{
			c = ft_char_to_str('$');
			tmp = ft_strjoin(c, splitted[0]);
			ht_set(g_shell.env, splitted[0], ft_strdup(splitted[1]));
			trie_insert(g_shell.env_trie, tmp);
			free(c);
			free(tmp);
			tmp = NULL;
		}
		free_tab(splitted);
	}
}
