/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/09 09:48:21 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	char	c;
	char	sc;
	size_t	len;

	if ((c = *find++) != '\0')
	{
		len = ft_strlen(find);
		while (1)
		{
			while (1)
			{
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
				if (sc == c)
					break ;
			}
			if (len > slen)
				return (NULL);
			if (ft_strncmp(s, find, len) == 0)
				break ;
		}
		s--;
	}
	return ((char *)s);
}
