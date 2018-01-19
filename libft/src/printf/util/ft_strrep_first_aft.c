/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrep_first_aft.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 12:43:36 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 14:31:38 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_query_i(const char *query, const char *str, int index)
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

int				strstr_i(const char *str, const char *query, int after)
{
	int i;

	i = 0;
	if (ft_strlen(query) == 0)
		return (-1);
	while (str[i])
	{
		if (str[i] == query[0] && i >= after)
		{
			if (is_query_i(query, str, i))
				return (i);
		}
		i++;
	}
	return (-1);
}

static char		*build_str(char *first, char *mid, char *last)
{
	char *tmp;
	char *ret;

	tmp = ft_strjoin(first, mid);
	ret = ft_strjoin(tmp, last);
	free(tmp);
	return (ret);
}

static char		*magic_hapn(int index, char *subject, char *search,
char *replace)
{
	char *tmp_1;
	char *tmp_2;
	char *ret;

	tmp_1 = ft_strsub(subject, 0, index);
	tmp_2 = ft_strsub(subject, index + ft_strlen(search),
			ft_strlen(subject) - (index + ft_strlen(search)));
	ret = build_str(tmp_1, replace, tmp_2);
	free(tmp_1);
	free(tmp_2);
	return (ret);
}

char			*ft_strrep_first_aft(char *search,
char *replace, char *subject, int n)
{
	int		index;
	char	*str;
	char	*tmp;

	if (!search || !replace || !subject)
		return (NULL);
	if (ft_strstr(subject, search) != NULL)
	{
		index = strstr_i(subject, search, n);
		if (index < n)
			return (NULL);
		if (index == 0)
		{
			str = ft_strsub(subject, ft_strlen(search), (ft_strlen(subject) -
			ft_strlen(search)));
			tmp = build_str("", replace, str);
			free(str);
			return (tmp);
		}
		else
			return (magic_hapn(index, subject, search, replace));
	}
	return (subject);
}
