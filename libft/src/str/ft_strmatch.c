/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmatch.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 21:35:43 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strmatch(const char *str, const char *match)
{
	if (!*str)
	{
		if (!*match)
			return (1);
		if (*match == '*')
			return (ft_strmatch(str, match + 1));
	}
	else if (*str == *match)
		return (ft_strmatch(str + 1, match + 1));
	else if (*match == '*')
	{
		if (!match[1])
			return (1);
		return (ft_strmatch(str, match + 1) || ft_strmatch(str + 1, match));
	}
	return (0);
}
