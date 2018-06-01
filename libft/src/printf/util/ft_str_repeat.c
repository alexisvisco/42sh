/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_repeat.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/27 11:02:38 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_repeat(char **str, char c, int n)
{
	int x;

	x = -1;
	while (++x < n)
		(*str)[x] = c;
}

char	*ft_str_repeatm(char c, int n)
{
	char	*str;
	int		x;

	str = ft_memalloc(sizeof(char) * (n + 1));
	str[n] = 0;
	x = -1;
	while (++x < n)
		str[x] = c;
	return (str);
}
