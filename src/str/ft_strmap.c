/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/10 18:30:15 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 10:51:33 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*map;
	unsigned int	i;

	i = 0;
	if (!s || !f || !(map = ft_strdup(s)))
		return (NULL);
	while (map[i])
	{
		map[i] = f(map[i]);
		i++;
	}
	return (map);
}
