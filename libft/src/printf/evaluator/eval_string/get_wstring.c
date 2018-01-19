/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_wstring.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 14:50:57 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 13:49:33 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_wstring(t_formatter *t, va_list lst)
{
	wchar_t	*arg;
	int		free_arg;
	int		h_z;

	h_z = ft_strchr(t->flags, '0') && !ft_strchr(t->flags, '-');
	free_arg = 0;
	arg = va_arg(lst, wchar_t *);
	if (!arg)
		return ;
	if ((t->precision > 0 && (int)ft_byte_wstrlen(arg) > t->precision) ||
	t->precision == 0)
	{
		wstr_precision(&arg, t);
		free_arg = 1;
	}
	free(t->to_replace);
	t->to_replace = ft_wstr_to_str(arg);
	if (free_arg)
		free(arg);
	if (!h_z && t->width > 0 && (int)ft_strlen(t->to_replace) < t->width)
		str_padding(t);
	if (h_z)
		number_zero(t);
}
