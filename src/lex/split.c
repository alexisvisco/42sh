/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   split.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 17:04:06 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 13:19:23 by ggranjon    ###    #+. /#+    ###.fr     */
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
	while (*s1 == *s2)
	{
		s1++;
		s2++;
		ret++;
	}
	return (ret);
}


char			*ft_specpy(char *s)
{
	char	*ret;
	int		i;
	int		mod;
	char	c;

	i = 0;
	ret = ft_strnew(ft_strlen(s));
	(*s == '\'' || *s == '\"' ) ? (mod = 1) : (mod = 0);
	mod == 1 ? (c = *s) : (c = '\"');
	ret[i++] = *(s++);
	while (*s)
	{
		if (mod % 2 == 0 && *s == ' ')
			break;
		if (*s == c && *(s - 1) != '\\')
		{
			ret[i++] = *(s++);
			mod++;
		}
		else
			ret[i++] = *(s++);
	}
	if (mod % 2)
		ft_strdel(&ret);
	return (ret);
}

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

/*
**	avancer tous les espaces, reconnaitre le mot, avancer les espaces, reconnaitre le mot

char			**ft_recognize(char *s)
{
	char	*word;

	while (*s)
	{
		while (*s == ' ')	
			s++;
		if (*s)
		{
			word = ft_specpy(s);
			
		}
		ft_strdel(&word);
	}
}*/