/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   recognize.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 17:07:59 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 17:40:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char			*ft_removeq(char *s)
{
	char	quote;
	char	*new;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(s) - 2);
	if (s[0] == '\'' || s[0] == '\"')
	{
		quote = s[0];
		while (s[i])
		{
			if (s[i] == quote && s[i - 1] != '\\')
				i++;
			else
				new[j++] = s[i++];
		}
	}
	else
		ft_strdel(&new);
	return (new ? new : NULL);
}

void		ft_lexall(t_token ***tokens, char *s)
{
	int	i;
	
	i = 0;
	*tokens = ft_splittokens(s);
	(*tokens)[0]->type = COMMAND;
//	while ()
/*	while (tokens[i])
		ft_printf("tokens %i : %s\n", i, tokens[i++]->value);*/
}