/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_env_unset.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 21:00:29 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void		b_unset_env_a(char *str, t_node *node, t_shell *shell)
{
	message(MSG_UNSETENV, str, node->value);
	ht_default_free(shell->env, node);
	if (ft_strequ("PATH", str))
		update_bin(shell);
}

/*
** Unset a environment variable
** Take one or more arguments
*/

int				b_env_unset(char **args, t_shell *shell)
{
	char	*str;
	t_node	*node;

	if (!args || size_tab(args) < 2)
	{
		message_err(ERR_UNSETENV_FORMAT);
		return (0);
	}
	while (*(++args))
	{
		str = *args;
		node = ht_remove(shell->env, str);
		if (node)
			b_unset_env_a(str, node, shell);
		else
		{
			message_err(ERR_UNSETENV_NOT_EXIST, str);
			return (0);
		}
	}
	return (1);
}
