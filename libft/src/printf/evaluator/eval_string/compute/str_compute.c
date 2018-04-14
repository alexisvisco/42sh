/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_compute.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 14:53:34 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_compute(t_formatter *t)
{
	int h_z;

	h_z = ft_strchr(t->flags, '0') && !ft_strchr(t->flags, '-');
	if (t->precision == 0 && !t->non_spec_arg)
		str_delprec_0(t);
	if (t->precision > 0 && (int)ft_strlen(t->to_replace) > t->precision)
		str_precision(t);
	if (!h_z && t->width > 0 && (int)ft_strlen(t->to_replace) < t->width)
		str_padding(t);
	if (h_z)
		number_zero(t);
}
