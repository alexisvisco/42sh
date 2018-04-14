/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strreplace_first.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 14:34:40 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*build_str(char *first, char *mid, char *last)
{
	return (ft_strjoin(ft_strjoin(first, mid), last));
}

char			*ft_strreplace_first(char *search, char *replace, char *subject)
{
	int		index;
	char	*str;

	if (!search || !replace || !subject)
		return (NULL);
	if (ft_strstr(subject, search) != NULL)
	{
		index = strstr_i(subject, search, 0);
		if (index == 0)
		{
			str = ft_strsub(subject, ft_strlen(search),
			ft_strlen(subject) - ft_strlen(search));
			return (build_str("", replace, str));
		}
		else
			return (build_str(ft_strsub(subject, 0, index), replace,
			ft_strsub(subject, index + ft_strlen(search),
			ft_strlen(subject) - (index + ft_strlen(search)))));
	}
	return (subject);
}
