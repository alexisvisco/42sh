/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 10:19:38 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 14:45:07 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char		*core_printf(const char *format, va_list ap)
{
	char		*to_write;
	int			i;
	int			j;

	i = 0;
	j = 0;
	to_write = ft_strnew(ft_strlen(format));
	while (format[i])
	{
		if (format[i] == '%')
		{
			format[i + 1] == 's' ? percent_s(format + i + 1, ap, &to_write) :
				percent_di(format + i + 1, ap, &to_write);
			i += 2;
			j = (int)ft_strlen(to_write);
		}
		else
			to_write[j++] = format[i++];
	}
	return (to_write);
}

void		core_dprintf(int fd, const char *format, va_list ap)
{
	char		*to_write;

	to_write = core_printf(format, ap);
	ft_putstr_fd(fd, to_write);
	free(to_write);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	char		*to_write;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	to_write = core_printf(format, ap);
	va_end(ap);
	ft_putstr(to_write);
	len = (int)ft_strlen(to_write);
	free(to_write);
	return (len);
}

char		*ft_sprintf(const char *format, ...)
{
	va_list		ap;
	char		*to_write;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	to_write = core_printf(format, ap);
	va_end(ap);
	return (to_write);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list		ap;
	char		*to_write;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	to_write = core_printf(format, ap);
	va_end(ap);
	ft_putstr_fd(fd, to_write);
	free(to_write);
	return (0);
}
