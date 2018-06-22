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

static int		replace_by_exec(char **cmds)
{
	char			*tmp;

	if (is_executable(cmds[0]) || builtins(cmds[0]) || builtins_env(cmds[0]))
		;
	else if ((tmp = ht_get(g_shell.bin, cmds[0])))
	{
		ft_memdel((void **)&(cmds[0]));
		cmds[0] = ft_strdup(tmp);
	}
	else
	{
		message_err(ERR_CMD_NOT_FOUND, cmds[0]);
		return (-1);
	}
	return (0);
}

static void		exec_bi(char **args, t_hashtable *envs,
	int (*buitlin)(char **, t_shell *))
{
	t_hashtable *temp;

	temp = g_shell.env;
	g_shell.env = envs;
	buitlin(args, &g_shell);
	g_shell.env = temp;
}

int				execute_env_cmd(char **args, t_hashtable *envs)
{
	t_builtins_fun	*buitlin;
	char			**envs_arr;

	(void)args;
	ft_memdel((void **)&(g_shell.line));
	if (replace_by_exec(args) == -1)
		;
	else if ((buitlin = builtins(args[0])))
		exec_bi(args, envs, buitlin);
	else
	{
		if (is_directory(args[0]))
			message_err(ERR_IS_DIR, args[0]);
		else
		{
			envs_arr = env_to_array(envs);
			execve(args[0], args, envs_arr);
			free_tab(envs_arr);
		}
	}
	return (1);
}
