/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/08 15:58:53 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 10:52:19 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		is_query(const char *query, const char *str, int index)
{
	int i;
	int ok;

	ok = 1;
	i = 0;
	while (query[i])
	{
		if (query[i] != str[i + index])
		{
			ok = 0;
			break ;
		}
		i++;
	}
	if (ok)
		return (1);
	return (0);
}

char			*ft_strstr(const char *str, const char *query)
{
	int i;

	i = 0;
	if (ft_strlen(query) == 0)
		return (char *)str;
	while (str[i])
	{
		if (str[i] == query[0])
		{
			if (is_query(query, str, i))
				return (char *)(str + i);
		}
		i++;
	}
	return (0);
}
