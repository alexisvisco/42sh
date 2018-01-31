/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:44:16 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 15:11:50 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "shell.h"

t_shell	g_shell;

int	main(void)
{
	char *str;

	set_env();
	set_bin();
	while ((str = readline("shell> ")))
	{
		if (ft_strequ("exit", str))
		{
			exit_shell();
			free(str);
			exit(0);
		}
		free(str);
	}
}
