/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 13:02:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/28 14:18:59 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "shell.h"

void	test(t_tok_type type)
{
	ft_printf("tok type = %i\n", type);
}


int		main(int args, char **argv)
{
	t_token	**tokens;
	t_block	*test;
	char	s[] = "  ls -t &| wc -c || #echo ; \"fd ; \\t\"s\"\" >mama  ; echo salut ca va ";
	
	tokens = NULL;
	test = NULL;

	ft_printf("Entrée standard : %s\n\n", s);
	if (parse_tokens(&tokens, s) == -1)
		printf("\nErreur parse tokens\n");

	int	i = 0;
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

	int	parse;
	
	if ((parse = parse_block(tokens, &test)) == -1)
		printf("\nErreur parse block\n");
	if (parse == -2)
		printf("\nQue des commentaires\n");
	i = 0;
	while (test[i].start_tok != -1)
	{
		ft_printf ("BLOCK begin : %i\tBLOCK end : %i\n", test[i].start_tok, test[i].end_tok);
		ft_printf ("IS RED : %i\n", test[i].isredir[0]);
		ft_printf ("Type RED : %i\n", test[i].isredir[1]);
		ft_printf ("Nombre de pipe : %i\n", test[i].nb_pipe);
		i++;
	}
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
	free(test);
}
