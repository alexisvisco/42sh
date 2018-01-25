/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 17:04:06 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 12:14:32 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

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
	if (ft_strchr(FT_SEP, **s) || ft_strchr(FT_REDIR, **s) ||
	(ft_isdigit(**s) && ft_strchr(FT_REDIR, (*(*s + 1)))))
	{
		i = 1;
		(*ret)[0] = **s;
		(*s)++;
		if (ft_strchr(FT_SEP, **s) || ft_strchr(FT_REDIR, **s))
		{
			(*ret)[1] = **s;
			(*s)++;
		}
	}
	return (i);
}

/*
**	if s begin by a quote (a ' or a ")
**  Mod = nb of quote NOT precedeed by '\' (backslash)
**	BIG CONDITION : new token if FT_SEP OR FT_REDIR or
*/

char			*specpy(char *s)
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
		if (mod % 2 == 0 && (*s == ' ' || ft_strchr(FT_SEP, *s) ||
		ft_strchr(FT_REDIR, *s) || (*S && ft_strchr(FT_REDIR, (*S)))))
			break ;
		if (*s == c && *(s - 1) != '\\')
			mod++;
		ret[i++] = *(s++);
	}
	(mod % 2) ? ft_strdel(&ret) : (long)mod;
	return (ret);
}

/*
**	if  -2 is returned : quotes problem
*/

int				count_tokens(char *s)
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
			word = specpy(s);
			nbword++;
			if (!word)
				return (-2);
			s += ft_endword(s, word);
		}
		ft_strdel(&word);
	}
	return (nbword);
}

t_token			**split_tokens(char *s, int nbtokens)
{
	t_token	**tokens;
	int		i;
	int		len;

	tokens = malloc(sizeof(t_token*) * (nbtokens + 1));
	i = 0;
	len = ft_strlen(s);
	while (i < nbtokens)
		tokens[i++] = malloc(sizeof(t_token));
	i = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
		{
			tokens[i]->value = specpy(s);
			tokens[i]->index = len - ft_strlen(s);
			s += ft_endword(s, tokens[i]->value);
			i++;
		}
	}
	tokens[i] = NULL;
	return (tokens);
}
