/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 17:04:06 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 18:59:09 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
/*
**	if s begin by a quote (a ' or a ")
**  Mod = nb of quote NOT precedeed by '\' (backslash)
*/

static int		ft_endword(char *s1, char *s2)
{
	int		ret;

	ret = 0;
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		ret++;
	}
	return (ret);
}

static int		ft_cpysep(char **s, char **ret)
{
	int	i;

	i = 0;
	if (ft_strchr(FT_SEP, **s) || ft_strchr(FT_REDIR, **s))
	{
		i = 1;
		*ret[0] = **s;
		(*s)++;
		if (ft_strchr(FT_SEP, **s) || ft_strchr(FT_REDIR, **s))
		{
			*ret[1] = **s;
			(*s)++;
		}
	}
	return (i);
}

char			*ft_specpy(char *s)
{
	char	*ret;
	int		i;
	int		mod;
	char	c;

	i = 0;
	ret = ft_strnew(ft_strlen(s));
	if (ft_cpysep(&s, &ret))
		return (ret);
	mod = (*s == '\'' || *s == '\"') ? 1 : 0;
	c = (mod == 1) ? *s : '\"';
	ret[i++] = *(s++);
	while (*s)
	{
		if (mod % 2 == 0 && (*s == ' ' || ft_strchr(FT_SEP, *s) || ft_strchr(FT_REDIR, *s)))
			break ;
		if (*s == c && *(s - 1) != '\\')
		{
			ret[i++] = *(s++);
			mod++;
		}
		else
			ret[i++] = *(s++);
	}
	(mod % 2) ? ft_strdel(&ret) : mod / 2;
	return (ret);
}

int				ft_counttoken(char *s)
{
	char	*word;
	int		nbword;

	nbword = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
		{
			word = ft_specpy(s);
			nbword++;
			s += ft_endword(s, word);
		}
		ft_strdel(&word);
	}
	return (nbword);
}

t_token			**ft_splittokens(char *s)
{
	t_token	**tokens;
	int		i;
	int		nbtokens;

	nbtokens = ft_counttoken(s);
	tokens = malloc(sizeof(t_token*) * (nbtokens + 1));
	i = 0;
	while (i < nbtokens)
		tokens[i++] = malloc(sizeof(t_token));
	i = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
		{
			tokens[i]->value = ft_specpy(s);
			s += ft_endword(s, tokens[i]->value);
			i++;
		}
	}
	tokens[i] = NULL;
	return (tokens);
}
