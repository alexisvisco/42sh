/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_cwd.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/21 10:44:23 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/21 10:44:23 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char 	*get_cwd(char *str, size_t s)
{
	if (ht_has(g_shell.env, "PWD"))
		ft_strcpy(str, ht_get(g_shell.env, "PWD"));
	else
		getcwd(str, s);
	return str;
}
