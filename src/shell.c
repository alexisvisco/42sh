/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 13:02:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 19:20:36 by ggranjon    ###    #+. /#+    ###.fr     */
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
	char	s[] = "ls;echo test";
	
	tokens = NULL;
	ft_printf("Entrée standard : %s\n", s);
	ft_lexall(&tokens, s);
	i = 0;
	while (tokens[i])
		ft_printf("tokens %i : %s\n", i, tokens[i++]->value);
}