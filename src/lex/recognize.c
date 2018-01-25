/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recognize.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 17:07:59 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 12:14:32 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char			*ft_removeq(char *s)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		if ((s[i] == '\'' || s[i] == '\"') && s[i - 1] != '\\')
			i++;
		else
			new[j++] = s[i++];
	}
	return (new);
}

static void		ft_minirecognize(t_token ***tokens)
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
		else if ((*tokens)[i - 1]->type == IO_REDIR)
			(*tokens)[i++]->type = FD_FILE;
		else
			(*tokens)[i++]->type = ARG;
	}
}

int				ft_lexall(t_token ***tokens, char *s)
{
	int		i;
	int		nbtokens;

	i = 1;
	if ((nbtokens = count_tokens(s)) == -2)
	{
		e_parse(ERR_QUOTE, NULL);
		return (-2);
	}
	else if (nbtokens == 0)
		return (-1);
	*tokens = split_tokens(s, nbtokens);
	ft_minirecognize(tokens);
	return(0);
}
