/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_multiple.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 21:41:12 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_multiple(int n, ...)
{
	va_list	ap;
	char	*tmp;
	char	*cpy;
	char	*full;

	full = ft_strdup("\0");
	va_start(ap, n);
	while (n--)
	{
		tmp = va_arg(ap, char *);
		if (!tmp)
			break ;
		cpy = full;
		full = ft_strjoin(cpy, tmp);
		ft_memdel((void **)&(cpy));
	}
	va_end(ap);
	return (full);
}
