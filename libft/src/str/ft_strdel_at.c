/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdel_at.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/13 14:29:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdel_at(char *str, int pos)
{
	size_t	size;
	char	*new;
	size_t	i;

	size = ft_strlen(str) - 1;
	new = ft_memalloc(sizeof(char) * (size + 1));
	new[size] = 0;
	i = 0;
	while (i <= size)
	{
		if (i != (size_t)pos)
			*new++ = str[i];
		i++;
	}
	return (new - size);
}

char	*ft_strdel_all_from(char *str, int pos)
{
	size_t	size;
	size_t	i;
	char	*new;

	i = 0;
	while (str[i] && i != (size_t)pos)
		i++;
	size = i;
	new = (char *)ft_memalloc(sizeof(char) * (size) + 1);
	i = 0;
	while (str[i] && i != (size_t)pos)
	{
		new[i] = str[i];
		i++;
	}
	new[size] = 0;
	return (new);
}

char	*ft_strdel_all_from_to(char *str, int from, int to)
{
	size_t	size;
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (!(j >= (size_t)from && j <= (size_t)to))
			i++;
		j++;
	}
	size = i;
	new = (char *)ft_memalloc(sizeof(char) * (size) + 1);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (!(j >= (size_t)from && j <= (size_t)to))
			new[i++] = str[j];
		j++;
	}
	new[size] = 0;
	return (new);
}
