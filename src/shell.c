/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:44:16 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 18:52:39 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

t_shell g_shell;

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
	while (tokens[i])
	{
		ft_printf("tokens %-2i : %-25s  valeur =  %i \n", i, tokens[i]->value, tokens[i]->type);
		i++;
	}
	ft_printf("value = %d => COMMAND\n", COMMAND);
	ft_printf("value = %d => ARG\n", ARG);
	ft_printf("value = 2 => IO_REDIR\n");
	ft_printf("value = 3 => SEP_OP\n");
	ft_printf("value = 4 => FD_FILE\n\n\n");

	int parse;

	if ((parse = parse_block(tokens, &test)) < 0)
		return (0);
		
	i = 0;
	while (test[i].start_tok != -1)
	{
		ft_printf("BLOCK begin : %i\tBLOCK end : %i\n", test[i].start_tok, test[i].end_tok);
		ft_printf("Typeee : %i\n", test[i].my_op[1]);
		ft_printf("Nombre de pipe : %i\n", test[i].nb_pipe);
		i++;
	}
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

	set_env();
	set_bin();
	while ((str = readline("shell> ")))
	{
		if (ft_strequ("exit", str))
		{
			free(str);
			exit(0);
		}
		main2(str);
		free(str);
	}
}
