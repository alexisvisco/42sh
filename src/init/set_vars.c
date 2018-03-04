/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_vars.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/26 13:57:53 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/26 13:57:53 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	set_vars(void)
{
	g_shell.vars = ht_new(64);
	g_shell.vars->free_func = free_variable;
}