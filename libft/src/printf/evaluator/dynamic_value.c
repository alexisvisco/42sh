/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   dynamic_value.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 11:14:17 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_arg(t_formatter *t, va_list lst)
{
	int i;

	i = va_arg(lst, int32_t);
	if (i < 0)
	{
		if (!ft_strchr(t->flags, '-'))
			ft_strcat_ch(t->flags, '-');
		i = -i;
	}
	return (i);
}

void		fill_dyn_val(t_formatter *t, va_list lst)
{
	if (t->is_width_first == 1 && t->width == -2)
	{
		t->width = get_arg(t, lst);
		t->width = t->width < 0 ? -1 : t->width;
	}
	else if (t->is_width_first == -1 && t->precision == -2)
	{
		t->precision = va_arg(lst, int32_t);
		t->precision = t->precision < 0 ? -1 : t->precision;
	}
	if (t->width == -2)
		t->width = get_arg(t, lst);
	else if (t->precision == -2)
		t->precision = va_arg(lst, int32_t);
	t->width = t->width < 0 ? 0 : t->width;
	t->precision = t->precision < 0 ? -1 : t->precision;
}
