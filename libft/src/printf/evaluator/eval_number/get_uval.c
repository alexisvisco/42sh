/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_uval.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/27 10:44:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_uval(t_formatter *t, uintmax_t *val, va_list lst)
{
	if (ft_strequ(t->length, "l") || t->type == 'U' || t->type == 'O')
		*val = (intmax_t)va_arg(lst, unsigned long);
	else if (ft_strequ(t->length, "z"))
		*val = (uintmax_t)va_arg(lst, size_t);
	else if (ft_strequ(t->length, "j"))
		*val = va_arg(lst, uintmax_t);
	else if (ft_strequ(t->length, "ll"))
		*val = (uintmax_t)va_arg(lst, unsigned long long);
	else if (ft_strequ(t->length, "h"))
		*val = (uintmax_t)(unsigned short)va_arg(lst, unsigned int);
	else if (ft_strequ(t->length, "hh"))
		*val = (uintmax_t)(unsigned char)va_arg(lst, unsigned int);
	else
		*val = (uintmax_t)va_arg(lst, unsigned int);
}
