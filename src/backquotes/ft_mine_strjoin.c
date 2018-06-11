/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mine_strjoin.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 19:56:38 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 19:57:43 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

char			*ft_mine_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*res;

	if ((!s1 || !(*s1)) && s2)
		return (ft_strdup(s2));
	if (!s2 || !(*s2))
		return (ft_strdup(s1));
	total_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = ft_memalloc(sizeof(char) * (total_size + 1))))
		return (NULL);
	res[total_size] = '\0';
	while (*s1)
	{
		*res++ = *s1;
		s1++;
	}
	*res++ = ' ';
	while (*s2)
	{
		*res++ = *s2;
		s2++;
	}
	return (res - total_size);
}
