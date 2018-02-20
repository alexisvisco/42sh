/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_append.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 18:37:40 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:26 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend_at(int n, char *src, char *add)
{
	size_t	size;
	char	*new;
	int		i;

	size = ft_strlen(src) + ft_strlen(add);
	new = (char *)malloc(sizeof(char) * (size + 1));
	new[size] = 0;
	i = -1;
	while ((size_t)(++i) < size)
	{
		if (i == n)
		{
			while (*add)
				new[i++] = *add++;
			i--;
		}
		else
			new[i] = *src++;
	}
	return (new);
}

char	*ft_strappend_atc(int n, char *src, char c)
{
	size_t	size;
	char	*new;
	int		i;

	size = ft_strlen(src) + 1;
	new = (char *)malloc(sizeof(char) * (size + 1));
	new[size] = 0;
	i = -1;
	while ((size_t)(++i) < size)
	{
		if (i == n)
			new[i] = c;
		else
			new[i] = *src++;
	}
	return (new);
}
