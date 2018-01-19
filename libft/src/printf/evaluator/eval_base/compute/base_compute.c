/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   base_compute.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/27 11:15:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 13:52:28 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#define B_ZERO_CHILD (ft_strchr(t->flags, '0') && !ft_strchr(t->flags, '-'))
#define B_HAS_ZERO ((B_ZERO_CHILD && !has_prec))

void	base_compute(t_formatter *t)
{
	int	has_prec;

	has_prec = (t->precision >= 0 && t->precision >
	(int)ft_strlen(t->to_replace));
	if (t->precision == 0 && ft_strequ(t->to_replace, "0"))
		base_delprec_0(t);
	if (ft_strchr(t->flags, '#'))
		base_hash(t);
	if (has_prec)
		number_precision(t);
	if (B_HAS_ZERO)
		base_zero(t);
	if ((!B_HAS_ZERO || ft_strchr(t->flags, '-')))
		if (t->width > 0 && (int)ft_strlen(t->to_replace) < t->width)
			str_padding(t);
}
