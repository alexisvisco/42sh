/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   is_builtins.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:44:23 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 12:15:30 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <builtins.h>


t_hashtable     *get_builtins()
{
	static t_hashtable *builtins_methods = NULL;

	if (!builtins_methods)
	{
		builtins_methods = ht_new(10);
		builtins_methods->free_func = NULL;
		ht_set(builtins_methods, "pwd", b_pwd);
		ht_set(builtins_methods, "env", b_env);
		ht_set(builtins_methods, "setenv", b_env_set);
		ht_set(builtins_methods, "unsetenv", b_env_unset);
		ht_set(builtins_methods, "clear", b_clear);
		ht_set(builtins_methods, "binary-search", b_binary_search);
		ht_set(builtins_methods, "exit", b_exit);
	}
	return (builtins_methods);
}

t_builtins_fun  *builtins(char *cmd)
{
	if (ht_has(get_builtins(), cmd))
		return ((t_builtins_fun *)ht_get(get_builtins(), cmd));
	else
		return (NULL);
}