/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bh_history_exec.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:55:33 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:55:56 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Execute a command without adding it to the history
*/

int	history_exe(char **args)
{
	char full_str[4096];
	char *tmp;

	full_str[0] = 0;
	args++;
	while (*args)
	{
		if (!ft_strstarts_with(*args, '-'))
		{
			if (full_str[0] != 0)
				ft_strcat(full_str, " ");
			ft_strcat(full_str, *args);
		}
		args++;
	}
	tmp = ft_strdup(full_str);
	shell_process(tmp);
	ft_memdel((void **)&tmp);
	return (1);
}
