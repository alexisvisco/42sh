/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit_f.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/10 09:35:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char *s, int (*is_del)(char))
{
	int i;
	int words;

	i = -1;
	words = 0;
	while (s[++i])
		if (((i != 0 && is_del(s[i]) &&
		!is_del(s[i - 1])) ||
		(s[i + 1] == '\0' && !is_del(s[i]))))
			words++;
	return (words);
}

static char		*get_word(char *s, int (*is_del)(char))
{
	int		i;
	int		size;
	char	*word;

	i = -1;
	size = 0;
	while (s[++i] && !is_del(s[i]))
		size++;
	word = ft_memalloc(sizeof(char) * (size + 1));
	word[size] = '\0';
	while (*s && !is_del(*s))
	{
		*word++ = *s;
		s++;
	}
	return (word - size);
}

char			**ft_strsplit_f(char *s, int (*is_del)(char))
{
	int		size;
	char	**tab;
	char	*str;

	if (!s)
		return (NULL);
	size = count_words(s, is_del);
	if (!(tab = ft_memalloc((size + 1) * sizeof(char*))))
		return (NULL);
	tab[size] = 0;
	str = s;
	while (*str)
	{
		if (!is_del(*str))
		{
			*tab++ = get_word(str, is_del);
			str += ft_strlen(get_word(str, is_del)) - 1;
		}
		str++;
	}
	return (tab - size);
}
