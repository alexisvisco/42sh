/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_export.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 13:56:31 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 13:56:31 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int 	export_help()
{
	ft_printf("export [NAME[=VALUE] ...]\nexport -p\n");
	ft_printf("Explanation of each arguments: \n");
	ft_printf("  -p: print all exported variables\n");
	return (1);
}

int		export_variable(char *arg)
{
	t_node	*node;
	t_var	*var;
	node = ht_has(g_shell.vars, arg);
	if (!node)
	{
		message_err(ERR_VAR_NOT_EXIST, arg);
		return (0);
	}
	node = ht_remove(g_shell.vars, arg);
	var = node->value;
	b_set_env_b(g_shell.env, var->symbol, var->value, &g_shell);
	free_node_variable(node);
	message(MSG_VAR_EXPORTED, arg);
	return (1);
}

int 	b_export(char **args, t_shell *sh)
{
	char ar[3];
	char *arg;

	(void)sh;
	if (ft_strequ(get_first_arg(args), "help"))
		return (export_help());
	parse_arguments(args, ar, "np");
	if (ft_strchr(ar, 'p'))
		return (b_env(args, sh));
	arg = get_first_arg(args);
	if (arg == NULL)
	{
		message_err(ERR_VAR_USAGE);
		return (0);
	}
	if (ft_strchr(arg, '='))
		return (b_set_env_a(g_shell.env, arg, sh));
	else
		return (export_variable(arg));
}