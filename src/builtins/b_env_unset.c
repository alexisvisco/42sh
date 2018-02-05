/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_env_unset.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 21:00:29 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 21:34:41 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void    b_unset_env_a(t_hashtable *envs, char *str, t_node *node)
{
	msg_builtins(MSG_UNSETENV, str, node->value);
	ht_default_free(envs, node);
	if (ft_strequ("PATH", str))
		update_bin();
}

int     b_env_unset(char **args, t_hashtable *envs)
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
		node = ht_remove(envs, str);
		if (node)
			b_unset_env_a(envs, str, node);
		else
		{
			err_builtins(ERR_UNSETENV_NOT_EXIST, str);
			return (0);
		}
		args++;
	}
	return (1);
}