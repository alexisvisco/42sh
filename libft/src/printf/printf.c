/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   printf.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 20:07:05 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:20:35 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	smart_printer(int fd, char *str, int ret)
{
	int next_null;

	if (!str)
		return (0);
	next_null = strstr_i(str, PRNT_NULL, 0);
	if (next_null == -1)
	{
		ret += write(fd, str, ft_strlen(str));
		return (ret);
	}
	ret += write(fd, str, next_null);
	ret += write(fd, "\0", 1);
	return (smart_printer(fd, str + (next_null + ft_strlen(PRNT_NULL)), ret));
}

char		*ft_sprintf(char *format, ...)
{
	char	*dup_fmt;
	va_list	ap;

	va_start(ap, format);
	dup_fmt = ft_strdup(format);
	evaluator_core(&dup_fmt, ap);
	va_end(ap);
	return (dup_fmt);
}

int			core_pf(int fd, const char *format, va_list lst)
{
	char	*dup_fmt;
	int		n;

	dup_fmt = ft_strdup(format);
	evaluator_core(&dup_fmt, lst);
	n = smart_printer(fd, dup_fmt, 0);
	free(dup_fmt);
	return (n);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		write;

	va_start(ap, format);
	write = core_pf(fd, format, ap);
	va_end(ap);
	return (write);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		write;

	va_start(ap, format);
	write = core_pf(1, format, ap);
	va_end(ap);
	return (write);
}
