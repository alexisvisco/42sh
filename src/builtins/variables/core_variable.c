/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_variable.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/02 09:59:24 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/02 09:59:24 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <expr.h>
#include "shell.h"

/*
** Get the value of a variable into string value
*/

char	*v_value_to_str(t_var *v)
{
	if (v->var_type == VAR_STRING)
		return (ft_strdup(v->value));
	if (v->var_type == VAR_NUMBER)
		return (ft_sprintf("%i", *(int *)v->value));
	return (ft_strdup("null"));
}

/*
** Ensure your have key=value and call this function after.
** Create a variable, set type and att it to g_shell.vars hashtable
*/

int		create_variable(char *assignation)
{
	char	**assign;
	t_var	*var;
	t_res	res;

	assign = ft_strsplit(assignation, '=');
	var = (t_var *)ft_memalloc(sizeof(t_var));
	if (ft_strlen(assign[0]) > 32)
	{
		free(var);
		free(assign);
		return (0);
	}
	var->var_type = get_type_of_assignation(assign[1]);
	ft_copy_str(var->symbol, assign[0]);
	eval_expr(assign[1], &res);
	if (var->var_type == VAR_NUMBER && !res.error)
		var->value = (void *)ft_sprintf("%i", res.res);
	else
		var->value = ft_strdup(assign[1]);
	if (res.error) free(res.error);
	ht_set(g_shell.vars, var->symbol, var);
	free_tab(assign);
	return (1);
}

int		is_assignation_variable(char *str)
{
	char **assign;

	assign = ft_strsplit(str, '=');
	if (size_tab(assign) == 2)
	{
		free_tab(assign);
		return (1);
	}
	free_tab(assign);
	return (0);
}

t_var_type get_type_of_assignation(char *str)
{
	(void)str;
	if (valid_expr(str)) {
		return (VAR_NUMBER);
	}
	return (VAR_STRING);
}