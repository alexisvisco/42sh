/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_env_set.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 21:00:29 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void 		b_set_env_b(t_hashtable *envs, char *key, char *val,
t_shell *shell)
{
	ht_set(envs, key, ft_strdup(val));
	trie_insert(g_shell.env_trie, key);
	if (ft_strequ("PATH", key))
		update_bin(shell);
	message(MSG_SETENV, key, val);
}

int				b_set_env_a(t_hashtable *envs, char *str, t_shell *shell)
{
	char **splitted;

	splitted = ft_strsplit(str, '=');
	if (size_tab(splitted) >= 2)
		b_set_env_b(envs, splitted[0], splitted[1], shell);
	else
	{
		message_err(ERR_SETENV_FORMAT);
		free_tab(splitted);
		return (0);
	}
	free_tab(splitted);
	return (1);
}

/*
** Set or create a environment variable (syntax: name=value)
** Take one or more arguments
*/

int				b_env_set(char **args, t_shell *shell)
{
	char *str;

	if (!args || size_tab(args) < 2)
	{
		message_err(ERR_SETENV_FORMAT);
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
			message_err(ERR_SETENV_FORMAT);
			return (0);
		}
	}
	return (1);
}
