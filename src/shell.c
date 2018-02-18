/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 12:35:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/18 12:35:00 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_shell	g_shell;

int			main(int n, char **args, char **env)
{
	char	*str;


	init_shell(env);
	(void)n;
	(void)args;
	if (!ht_get(g_shell.env, "TERM"))
	{
		message_err(TERM_ENV_NOT_SET, NULL);
		exit_shell();
		exit(EXIT_FAILURE);
	}
	while ((str = readline(SHELL_NAME"> ", g_shell.line_edit)))
	{
		signal(SIGINT, sig_handler);
		str = multi_line_prompt(str, 1);
		str = replace_env_variables(str, 1);
		shell_process(str);
		free(g_shell.line);
	}
	return (0);
}
