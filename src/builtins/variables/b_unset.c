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

static int 	unset_help()
{
	ft_printf("unset NAME.\n");
	return (1);
}

static int		unset_variable(char *arg)
{
	t_node *node;
    t_var *var;
    char *to_print;
	node = ht_has(g_shell.vars, arg);

	if (!node)
	{
		message_err(ERR_VAR_NOT_EXIST, arg);
		return (0);
	}
	node = ht_remove(g_shell.vars, arg);
    var = node->value;
    to_print = ft_sprintf("%s=%s", var->symbol, var->value);
	message(MSG_VAR_UNSETED, to_print);
	free_node_variable(node);
    free(to_print);
	return (1);
}

int 			b_unset(char **args, t_shell *sh)
{
	char ar[3];
	char *arg;

	(void)sh;
	if (ft_strequ(get_first_arg(args), "help"))
		return (unset_help());
	parse_arguments(args, ar, "np");
	arg = get_first_arg(args);
	if (arg == NULL)
	    return (unset_help());
	else
		return (unset_variable(arg));
}