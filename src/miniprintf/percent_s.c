/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   percent_s.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 13:10:30 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 13:10:30 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		percent_s(const char *format, va_list ap, char **to_write)
{
	char		*tmp;
	char		*tmp2;

	if (*format == 's')
	{
		if ((tmp2 = va_arg(ap, char*)))
		{
			tmp = ft_strnew(ft_strlen(tmp2) + ft_strlen((*to_write))
							+ ft_strlen(format + 1));
			ft_strcpy(tmp, (*to_write));
			ft_strcat(tmp, tmp2);
			free((*to_write));
			(*to_write) = tmp;
		}
	}
}
