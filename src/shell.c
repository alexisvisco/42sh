/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:44:16 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 14:48:03 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "f_colors.h"

t_shell	g_shell;

int	main2(char *s)
{
	t_token **tokens;
	t_block *test;
	int i;

	tokens = NULL;
	test = NULL;
	if (parse_tokens(&tokens, s) == -1)
		printf("\nErreur parse tokens\n");
	i = 0;

	int parse;

	if ((parse = parse_block(tokens, &test)) < 0)
		return (0);
	int		tablea[2] = {0, 0};


	exec_or_and(tokens, test, tablea, 0);

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
	free(test);
	return (0);
}

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
		main2(str);
		free(str);
	}
}
