/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_env_unset.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 21:00:29 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 18:27:46 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void    b_unset_env_a(char *str, t_node *node, t_shell *shell)
{
	msg_builtins(MSG_UNSETENV, str, node->value);
	ht_default_free(shell->env, node);
	if (ft_strequ("PATH", str))
		update_bin(shell);
}

int     b_env_unset(char **args, t_shell *shell)
{
	char    *str;
	t_node  *node;

	if (!args)
	{
		err_builtins(ERR_UNSETENV_FORMAT);
		return (0);
	}
	while (*args)
	{
		str = *args;
		node = ht_remove(shell->env, str);
		if (node)
			b_unset_env_a(str, node, shell);
		else
		{
			err_builtins(ERR_UNSETENV_NOT_EXIST, str);
			return (0);
		}
		args++;
	}
	return (1);
}