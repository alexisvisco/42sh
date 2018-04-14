/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extract_precision.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 14:29:42 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	child_fn(char *precision)
{
	precision[0] = '0';
	precision[1] = 0;
}

void		extract_precision(t_formatter *fmt, char **str)
{
	char	precision[11];
	uint8_t	i;

	i = 0;
	precision[i] = 0;
	if (**str != '.')
		return ;
	(*str)++;
	if (**str == '*')
	{
		fmt->precision = -2;
		fmt->is_width_first = fmt->is_width_first == 1 ? 1 : -1;
		(*str)++;
		return ;
	}
	if (!ft_isdigit(**str))
		child_fn(precision);
	else
	{
		while (**str && ft_isdigit(**str))
			*str += (i < 10 ? !!(precision[i++] = **str) : 1);
		precision[i] = 0;
	}
	if (precision[0])
		fmt->precision = ft_atoi(precision);
}
