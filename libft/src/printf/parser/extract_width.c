/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extract_width.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 14:05:20 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 13:26:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	extract_width(t_formatter *fmt, char **str)
{
	char	width[11];
	uint8_t	i;

	if (**str == '*')
	{
		fmt->width = -2;
		fmt->is_width_first = fmt->is_width_first == -1 ? -1 : 1;
		(*str)++;
		return ;
	}
	i = 0;
	width[i] = 0;
	while (**str && ft_isdigit(**str))
		*str += (i < 10 ? !!(width[i++] = **str) : 1);
	width[i] = 0;
	if (width[0])
		fmt->width = ft_atoi(width);
}
