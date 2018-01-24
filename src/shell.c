/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 13:02:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 18:33:47 by ggranjon    ###    #+. /#+    ###.fr     */
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
	int		i;
	char	s[] = "  ls -t &> lol &| cat \"fd ; \\\" s\" >mama   ; echo salut ca va   ";	
	tokens = NULL;
	ft_printf("Entrée standard : %s\n\n", s);
	ft_lexall(&tokens, s);
	i = 0;
	while (tokens[i])
	{
		ft_printf("tokens %-2i : %-15s  valeur =  %i \n", i, tokens[i]->value, tokens[i]->type);
		i++;
	}
	ft_printf ("value = %d => COMMAND\n", COMMAND);
	ft_printf ("value = %d => ARG\n", ARG);
	ft_printf ("value = 2 => IO_REDIR\n");
	ft_printf ("value = 3 => SEP_OP\n");
	ft_printf ("value = 4 => FD_FILE\n\n\n");
	
	t_block	*test;
	test = extractblock(tokens);
	i = 0;
	while (test[i].start_tok != -1)
	{
		ft_printf ("BLOCK begin : %i\tBLOCK end : %i\n", test[i].start_tok, test[i].end_tok);
		ft_printf ("IS RED : %i\n", test[i].isredir);
		i++;
	}
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
	free(test);
}
