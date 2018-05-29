/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 12:35:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_shell	g_shell;

static void		init(char **env)
{
	init_shell(env);
	if (!ht_get(g_shell.env, "TERM"))
	{
		message_err(TERM_ENV_NOT_SET, NULL);
		exit_shell();
		exit(EXIT_FAILURE);
	}
}

int				main(int n, char **args, char **env)
{
	char	*str;
	char	prompt[255];

	(void)n;
	(void)args;
	init(env);
	while (set_prompt(prompt) && (str = readline(prompt, g_shell.line_edit)))
	{
		signal(SIGINT, sig_handler);
		str = multi_line_prompt(str, 1);
		shell_process(str);
		free(g_shell.line);
		g_shell.line = NULL;
	}
	return (0);
}
