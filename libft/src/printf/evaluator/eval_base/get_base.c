/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_base.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 20:10:42 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 21:45:11 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_hex(t_formatter *t, va_list lst)
{
	uintmax_t	val;
	char		*str;

	get_uval(t, &val, lst);
	free(t->to_replace);
	str = malloc(sizeof(char) * 256);
	str_uintmax(str, val, 16, t->type == 'X' ? BASE_CAPS : BASE);
	t->to_replace = str;
	base_compute(t);
}

void	get_oct(t_formatter *t, va_list lst)
{
	uintmax_t	val;
	char		*str;

	get_uval(t, &val, lst);
	free(t->to_replace);
	str = malloc(sizeof(char) * 256);
	str_uintmax(str, val, 8, BASE);
	t->to_replace = str;
	base_compute(t);
}
