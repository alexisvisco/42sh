/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/10 10:02:28 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	if (s)
	{
		i = 0;
		j = ft_strlen((char *)s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (!(tmp = (char *)ft_memalloc(sizeof(char) * (j - i + 1))))
			return (NULL);
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		k = 0;
		while (i <= j)
		{
			tmp[k++] = s[i];
			i++;
		}
		tmp[k] = '\0';
		return (tmp);
	}
	return (NULL);
}
