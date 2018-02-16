/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   is_builtins.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:44:23 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:13:55 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "builtins.h"

t_hashtable		*get_builtins(void)
{
	static t_hashtable *builtins_methods = NULL;

	if (!builtins_methods)
	{
		builtins_methods = ht_new(10);
		builtins_methods->free_func = NULL;
		ht_set(builtins_methods, "pwd", b_pwd);
		ht_set(builtins_methods, "env", b_env);
		ht_set(builtins_methods, "echo", b_echo);
		ht_set(builtins_methods, "setenv", b_env_set);
		ht_set(builtins_methods, "unsetenv", b_env_unset);
		ht_set(builtins_methods, "clear", b_clear);
		ht_set(builtins_methods, "history", b_history);
		ht_set(builtins_methods, "cd", b_cd);
		ht_set(builtins_methods, "searchbin", b_search_binary);
		ht_set(builtins_methods, "exit", b_exit);
		ht_set(builtins_methods, "quit", b_exit);
	}
	return (builtins_methods);
}

static int		is_builtins_env(char *cmd)
{
	const char	*builtins_env[] = {"setenv", "unsetenv", "cd",
	"exit", "quit", "clear", 0};
	int			i;

	i = -1;
	while (builtins_env[++i])
	{
		if (ft_strequ(cmd, builtins_env[i]))
			return (1);
	}
	return (0);
}

t_builtins_fun	*builtins(char *cmd)
{
	if (ht_has(get_builtins(), cmd))
		return ((t_builtins_fun *)ht_get(get_builtins(), cmd));
	else
		return (NULL);
}

t_builtins_fun	*builtins_env(char *cmd)
{
	if (ft_strstarts_with(cmd, '!'))
		return (b_history_handler(cmd));
	if (is_builtins_env(cmd))
		return ((t_builtins_fun *)ht_get(get_builtins(), cmd));
	else
		return (NULL);
}
