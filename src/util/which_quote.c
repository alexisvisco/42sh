/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   which_quote.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/05 23:00:34 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 23:00:34 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

#define C_DIF_BS (*s == c && *(s - 1) != '\\')
#define IS_QUO (*s == '\"' || *s == '\'' || *s == '`')

static char	which_one(char *s)
{
	char	*ret;
	int		i;
	int		mod;
	char	c;

	i = 0;
	ret = ft_strnew(ft_strlen(s));
	mod = (*s == '\'' || *s == '\"' || *s == '`') ? 1 : 0;
	c = (mod == 1) ? *s : (char)-2;
	ret[i++] = *(s++);
	while (*s)
	{
		if (mod % 2 == 0 && (c == '`' || *s == ' ' || ft_strchr(FT_SEP, *s) ||
		ft_strchr(FT_REDIR, *s) || (*S && ft_strchr(FT_REDIR, (*S)))))
			break ;
		if (C_DIF_BS || (c == -2 && IS_QUO && *(s - 1) != '\\' && (c = *s)))
			mod++;
		ret[i++] = *(s++);
		if (mod % 2 == 0)
			c = (char)-2;
	}
	ft_strdel(&ret);
	return ((mod % 2) ? c : (char)0);
}

char		which_quote(char *s)
{
	char	*word;

	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if (*s)
		{
			word = cpy_special(s);
			if (!word)
				return (which_one(s));
			s += nb_equal_char(s, word);
			ft_strdel(&word);
		}
	}
	return (0);
}
