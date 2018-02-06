/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:44:16 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 18:28:19 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "f_colors.h"

t_shell	g_shell;

int		main(void)
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
		char **s = ft_split(str, " ");
		t_builtins_fun *f = builtins(s[0]);
		if (f)
			f(s + 1, &g_shell);
		free(str);
	}
}
