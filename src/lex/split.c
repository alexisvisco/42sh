/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 17:04:06 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void		simplify_cpy(char **s, char **ret, int a)
{
	(*ret)[a] = **s;
	(*s)++;
}

/*
** if there is a separator into a string, cut the seperator and the string
*/

static int		cpy_seprator(char **s, char **ret)
{
	int	i;

	i = 0;
	if (ft_strchr(FT_SEP, **s) || ft_strchr(FT_REDIR, **s) ||
	(ft_isdigit(**s) && ft_strchr(FT_REDIR, (*(*s + 1)))))
	{
		i = 1;
		simplify_cpy(s, ret, 0);
		if ((ft_strchr(FT_SEP, **s) && !(ft_isdigit((*ret)[0])))
		|| ft_strchr(FT_REDIR, **s))
		{
			simplify_cpy(s, ret, 1);
			if (((*ret)[1] == '&' && ft_isdigit(**s)) || ((*ret)[1] == '>' &&
					**s == '&') || (ft_isdigit((*ret)[0]) && **s == '>'))
			{
				simplify_cpy(s, ret, 2);
				if ((*ret)[2] == '&' && (ft_isdigit(**s) || **s == '-'))
					simplify_cpy(s, ret, 3);
			}
		}
	}
	return (i);
}

/*
**	copy the *s if "" = everything in the quotes
**	else cut to the next space or separator or redirection
**
**	if s begin by a quote (a ' or a ")
**  Mod = nb of quote NOT precedeed by '\' (backslash)
**	BIG CONDITION : new token if FT_SEP OR FT_REDIR or
*/

char			*cpy_special(char *s)
{
	char	*ret;
	int		i;
	int		mod;
	char	c;

	i = 0;
	ret = ft_strnew(ft_strlen(s));
	if (cpy_seprator(&s, &ret))
		return (ret);
	mod = (*s == '\'' || *s == '\"' || *s == '`') ? 1 : 0;
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
			tokens[i]->value = cpy_special(s);
			tokens[i]->index = len - ft_strlen(s);
			s += nb_equal_char(s, tokens[i]->value);
			i++;
		}
	}
	tokens[i] = NULL;
	return (tokens);
}
