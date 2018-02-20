/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recognize.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 17:07:59 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** detect the type of the argument thanks to the previous one
*/

static void		recognize_type(t_token ***tokens)
{
	int		i;

	i = 0;
	while ((*tokens)[i])
	{
		if (ft_strchr(FT_REDIR, (*tokens)[i]->value[0]) || ((*tokens)[i]->value
		[1] && ft_strchr(FT_REDIR, (*tokens)[i]->value[1])) ||
		(ft_isdigit((*tokens)[i]->value[0]) && (*tokens)[i]->value[1] &&
		ft_strchr(FT_REDIR, (*tokens)[i]->value[1])))
			(*tokens)[i++]->type = IO_REDIR;
		else if (ft_strchr(FT_SEP, (*tokens)[i]->value[0]))
			(*tokens)[i++]->type = SEP_OP;
		else if (i == 0 || ((*tokens)[i - 1]->type == SEP_OP))
			(*tokens)[i++]->type = COMMAND;
		else if ((*tokens)[i - 1]->type == IO_REDIR &&
		ft_strlen((*tokens)[i - 1]->value) <= 3)
			(*tokens)[i++]->type = FD_FILE;
		else
			(*tokens)[i++]->type = ARG;
	}
}

int				lex_all(t_token ***tokens, char *s)
{
	int		nbtokens;

	if ((nbtokens = count_tokens(s)) == -2)
	{
		odd_quote_prompt(tokens, s);
		return (-3);
	}
	else if (nbtokens == 0)
		return (-1);
	*tokens = split_tokens(s, nbtokens);
	recognize_type(tokens);
	return (0);
}
