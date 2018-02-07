/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_env_set.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 21:00:29 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 12:24:19 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int     b_set_env_a(t_hashtable *envs, char *str, t_shell *shell)
{
	char **splitted;

	splitted = ft_strsplit(str, '=');
	if (size_tab(splitted) >= 2)
	{
		ht_set(envs, splitted[0], ft_strdup(splitted[1]));
		trie_insert(g_shell.env_trie, splitted[0]);
		if (ft_strequ("PATH", splitted[0]))
			update_bin(shell);
		msg_builtins(MSG_SETENV, splitted[0], splitted[1]);
	}
	else
	{
		err_builtins(ERR_SETENV_FORMAT);
		free_tab(splitted);
		return (0);
	}
	free_tab(splitted);
	return (1);
}

int     b_env_set(char **args, t_shell *shell)
{
	char *str;

	if (!args || size_tab(args) < 2)
	{
		err_builtins(ERR_SETENV_FORMAT);
		return (0);
	}
	while (*(++args))
	{
		str = *args;
		if (ft_strchr(str, '=') && ft_strlen(str) > 2 &&
		b_set_env_a(shell->env, str, shell))
			;
		else
		{
			err_builtins(ERR_SETENV_FORMAT);
			return (0);
		}
	}
	return (1);
}