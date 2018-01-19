/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lex.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 17:04:06 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/19 19:41:24 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
**  The bizard if, is for the " or ' followed by characters
*/

char	*ft_specpy(char *s, char c)
{
	char	*ret;
	int		i;
	
	ret = ft_strnew(ft_strlen(s) - 2);
	s++;
	i = 0;
	while (*s)
	{
		if (*s == '\\')
		{
			ret[i++] = *(s++);
			ret[i++] = *(s++);
		}
		if (*s == c && ((*(s + 1) && *(s + 1) == ' ') || (!*(s + 1))))
			break;
		else if (*s == c)
			ret[i++] = *(s++);
		else if (*s != '\\')
			ret[i++] = *(s++);
	}
	return (ret);
}

fonction
	if (*s == '\'')
	{
		s++;
		while (*s && *s != '\'')
		{
			s++;
			if (*s == '\'')
				break;
			if (*s == '\\')
				s++;
		}
	}
char	*ft_cpyuntil(char *s)
{
	if (*s == '\"')
	until '\"' unless if ((*s + 1)  && (*s + 1) != ' ' || *(s-1)  == '\\')
	if (*s == '\'')
	until '\"'
	else	
}

int		ft_recognize(char *s, t_list **tokens)
{
	while (*s == ' ')
		s++;
	if (!*s)
		return (-1);
	while (*s && *s != ' ')
		s++;
}

int		ft_lexer(char *s, t_list **tokens)
{
}