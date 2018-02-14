/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstarts_with.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/10 17:55:55 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 18:23:55 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstarts_with(const char *s, char c)
{
	return (s && s[0] == c);
}

int		ft_strstarts_with_str(const char *s, char *str)
{
	int i;

	i = 0;
	while (s && (s[i] == str[i]))
		i++;
	return (i == ((int)ft_strlen(str)));
}
