/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_pointer.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/28 11:50:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_pointer(t_formatter *t, va_list lst)
{
	uintmax_t	pointer;
	char		*str;

	pointer = va_arg(lst, uintmax_t);
	str = ft_memalloc(sizeof(char) * 256);
	str_uintmax(str, pointer, 16, BASE);
	ft_memdel((void **)&(t->to_replace));
	t->to_replace = str;
	base_hash(t);
	pointer_compute(t);
}
