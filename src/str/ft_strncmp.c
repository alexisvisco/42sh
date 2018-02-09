/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/10/20 20:17:45 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 10:51:44 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	if (*s1 == '\0' || *s2 == '\0')
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	i = -1;
	while (++i < n && *s1++ == *s2++ && !(*s1 == '\0' && *s2 == '\0'))
		;
	return (*((unsigned char *)s1 - 1) - *((unsigned char *)s2 - 1));
}
