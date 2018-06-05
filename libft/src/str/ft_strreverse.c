/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strreverse.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 12:26:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 12:26:35 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *s)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = (ft_strlen(s) - 1);
	if (s[i] == '-')
		i++;
	while (i < len)
	{
		tmp = s[len];
		s[len] = s[i];
		s[i] = tmp;
		i++;
		len--;
	}
	return (s);
}
