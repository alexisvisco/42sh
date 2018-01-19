/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   number_compute.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/28 10:08:12 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 13:52:43 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#define N_ZERO_CHILD (ft_strchr(t->flags, '0') && !ft_strchr(t->flags, '-'))
#define N_HAS_ZERO ((N_ZERO_CHILD && !has_precision))

void	number_compute(t_formatter *t)
{
	int has_precision;
	int is_unsigned;

	has_precision = (t->precision >= 0 && t->precision >
	(int)ft_strlen(t->to_replace));
	is_unsigned = t->type == 'u' || t->type == 'U';
	if (t->precision == 0 && ft_strequ(t->to_replace, "0"))
		base_delprec_0(t);
	if (has_precision)
		number_precision(t);
	if (N_HAS_ZERO)
		number_zero(t);
	if (ft_strchr(t->flags, ' ') && !is_unsigned && !ft_strchr(t->flags, '+'))
		number_space(t);
	if (ft_strchr(t->flags, '+') && !is_unsigned)
		number_plus(t);
	if ((!N_HAS_ZERO || ft_strchr(t->flags, '-')))
		if (t->width > 0 && (int)ft_strlen(t->to_replace) < t->width)
			str_padding(t);
}
