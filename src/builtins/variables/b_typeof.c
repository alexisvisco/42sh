/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_typeof.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 13:56:31 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 13:56:31 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int 	typeof_help()
{
	ft_printf("typeof NAME.\n");
	return (1);
}

static int		typeof_variable(char *arg)
{
	t_node *node;
    t_var *var;

	node = ht_has(g_shell.vars, arg);
	if (!node)
	{
		message_err(ERR_VAR_NOT_EXIST, arg);
		return (0);
	}
	var = ht_get(g_shell.vars, arg);
	message(MSG_VAR_TYPEOF, var->symbol, var->var_type == 0 ? "String" : "Number");
	return (1);
}

int 			b_typeof(char **args, t_shell *sh)
{
	char ar[3];
	char *arg;

	(void)sh;
	if (ft_strequ(get_first_arg(args), "help"))
		return (typeof_help());
	parse_arguments(args, ar, "np");
	arg = get_first_arg(args);
	if (arg == NULL)
	    return (typeof_help());
	else
		return (typeof_variable(arg));
}