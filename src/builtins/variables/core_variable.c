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

#include "shell.h"

char	*v_value_to_str(t_var *v)
{
	if (v->var_type == VAR_STRING)
		return (ft_strdup(v->value));
	if (v->var_type == VAR_NUMBER)
		return (ft_sprintf("%i", *(int *)v->value));
}