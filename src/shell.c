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
	int i;

	i = -1;
	while (env[++i])
	{
		if (ft_strstarts_with_str(env[i], "TERM="))
		{
			init_shell(env);
			return ;
		}
	}
	message_err(TERM_ENV_NOT_SET, NULL);
	exit(EXIT_FAILURE);
}

void				test(int i) {
	(void)i;
	exit_shell();
	exit(0);
}

int				main(int n, char **args, char **env)
{
	char	*str;
	char	prompt[256];

	(void)n;
	(void)args;
	signal(SIGINT, sig_handler);
	signal(SIGIO, sig_handler);
	signal(SIGSEGV, test);
	if (!isatty(STDIN_FILENO))
	{
		message_err(ERR_UNSUPORTED_OPERATION);
		exit(EXIT_FAILURE);
	}
	init(env);
	while (set_prompt(prompt) && (str = readline(prompt, g_shell.line_edit)))
	{
		str = multi_line_prompt(str, 1);
		shell_process(str, 0);
		int * p = NULL;
		*p = 12;
	}
	return (0);
}
