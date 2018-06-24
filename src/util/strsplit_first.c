/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strsplit_first.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 15:20:55 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/18 15:20:55 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

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

char			**strsplit_first(char *str, const char *separator)
{
	char	**t;
	int		i;

	t = ft_memalloc(3);
	t[0] = ft_memalloc(ft_strlen(str));
	t[1] = ft_memalloc(ft_strlen(str));
	i = -1;
	while (str && separator && str[++i])
	{
		if (i == 0 && is_query(separator, str, i))
			return (t);
		else if (!is_query(separator, str, i))
		{
			t[0][ft_strlen(t[0])] = str[i];
			t[0][ft_strlen(t[0])] = '\0';
		}
		else
		{
			i += ft_strlen(separator);
			ft_copy_str(t[1], str + i);
			break ;
		}
	}
	return (t);
}
