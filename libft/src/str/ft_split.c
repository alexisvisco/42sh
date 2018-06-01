/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 21:07:41 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		is_in(char c, char *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

char	*ft_str_split_dup(char *str, char *charset)
{
	int		n;
	char	*tmp;

	n = 0;
	while (str[n] && !is_in(str[n], charset))
		n++;
	tmp = ft_memalloc(sizeof(char) * (n + 1));
	while (*str && !is_in(*str, charset))
		*tmp++ = *str++;
	*tmp = '\0';
	return (tmp - n);
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**tab;
	char	*tmp;

	size = 0;
	tmp = str;
	while (*tmp)
		if (!is_in(*tmp++, charset)
				&& (is_in(*tmp, charset)))
			size++;
	if (!is_in(*(tmp - 1), charset))
		size++;
	tab = ft_memalloc((size + 1) * sizeof(char*));
	tab[size] = 0;
	if (!is_in(*str, charset))
		*tab++ = ft_str_split_dup(str, charset);
	while (*++str && *(str + 1))
		if ((is_in(*str, charset)) && !is_in(*(str + 1), charset))
			*tab++ = ft_str_split_dup(++str, charset);
	return (tab - size);
}
