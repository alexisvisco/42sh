/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_env.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 10:35:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 21:05:10 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

extern char	**environ;

/*
** Retrieve all paths from environ and add it to a hashtable
*/

void	set_env()
{
	int		i;
	char	**splitted;

	g_shell.env = ht_new(128);
	i = -1;
	while (environ[++i])
	{
		splitted = ft_strsplit(environ[i], '=');
		if (splitted && splitted[0] && splitted[1])
			ht_set(g_shell.env, splitted[0], ft_strdup(splitted[1]));
		free_tab(splitted);
	}
}