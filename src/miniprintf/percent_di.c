/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   percent_di.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 13:13:14 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 14:27:37 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	percent_di(const char *format, va_list ap, char **to_write)
{
	char		*tmp;
	int			tmp2;
	char		*tmp3;

	if (*format == 'd' || *format == 'i')
	{
		tmp2 = va_arg(ap, int);
		tmp3 = ft_itoa_base(tmp2, 10);
		tmp = ft_strnew(ft_strlen(tmp3) + ft_strlen((*to_write))
						+ ft_strlen(format + 1));
		ft_strcpy(tmp, (*to_write));
		ft_strcat(tmp, tmp3);
		free((*to_write));
		free(tmp3);
		(*to_write) = tmp;
	}
}
