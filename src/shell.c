/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:44:16 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 11:49:31 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "f_colors.h"

t_shell	g_shell;

int	main(void)
{
	char	*str;

	init_shell();
	if (!ht_get(g_shell.env, "TERM"))
	{
		e_general(TERM_ENV_NOT_SET, NULL);
		exit_shell();
		exit(EXIT_FAILURE);
	}
	while ((str = readline("shell> ", g_shell.line_edit)))
	{
		if (ft_strequ("exit", str))
		{
			exit_shell();
			free(str);
			exit(0);
		}
		ft_printf("You wrote: %s%s%s$. \n", L_GREEN, str, RESET_ALL);
		free(str);
	}
}
