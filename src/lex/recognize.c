/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recognize.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 17:07:59 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:03:27 by ggranjon    ###    #+. /#+    ###.fr     */
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
		ft_strlen((*tokens)[i - 1]->value) <= 2)
			(*tokens)[i++]->type = FD_FILE;
		else
			(*tokens)[i++]->type = ARG;
	}
}

int				lex_all(t_token ***tokens, char *s)
{
	int		nbtokens;
	char	*new_line;
	char	*tmp;

	if ((nbtokens = count_tokens(s)) == -2)
	{
		free(*tokens);
		nbtokens = which_quote(s);
		new_line = heap_to_str(ask_line("dquote> ", 1, odd_quote,
			nbtokens == -3 ? "\"" : "\'"));
		tmp = new_line;
		new_line = ft_strjoin(s, new_line);
		free(tmp);
		g_shell.line = new_line;
		free(s);
		shell_process(new_line);
		return (-3);
	}
	else if (nbtokens == 0)
		return (-1);
	*tokens = split_tokens(s, nbtokens);
	recognize_type(tokens);
	return (0);
}
