/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   evaluator.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 20:18:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/05 14:31:29 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	evaluate(char **str, void (*fn)(), t_formatter *fmt, va_list lst)
{
	char *to_free;
	char *tmp;

	if (fmt->precision == -2 || fmt->width == -2)
		fill_dyn_val(fmt, lst);
	to_free = *str;
	fn(fmt, lst);
	tmp = ft_strrep_first_aft(fmt->full_formatter,
	fmt->to_replace, *str, fmt->index);
	fmt->index_replace_end = fmt->index + ft_strlen(fmt->to_replace);
	free(str[0]);
	str[0] = tmp;
}

void	evaluator(char **str, t_formatter *fmt, va_list lst)
{
	if (ft_strchr(STR_S, fmt->type))
		evaluate(str, get_string, fmt, lst);
	else if (ft_strchr(CHAR_S, fmt->type))
		evaluate(str, get_char, fmt, lst);
	else if (ft_strchr(BASE_SX, fmt->type))
		evaluate(str, get_hex, fmt, lst);
	else if (ft_strchr(BASE_SO, fmt->type))
		evaluate(str, get_oct, fmt, lst);
	else if (ft_strchr(NUMBER_INTS, fmt->type))
		evaluate(str, get_number, fmt, lst);
	else if (ft_strchr(NUMBER_UINTS, fmt->type))
		evaluate(str, get_unumber, fmt, lst);
	else if (fmt->type == 'p')
		evaluate(str, get_pointer, fmt, lst);
}
