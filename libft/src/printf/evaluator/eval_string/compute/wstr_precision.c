/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wstr_precision.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/26 11:15:44 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:26 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	wstr_precision(wchar_t **w, t_formatter *t)
{
	wchar_t *tmp;

	if (t->precision == 0)
	{
		tmp = malloc(sizeof(wchar_t) * 1);
		tmp[0] = L'\0';
		*w = tmp;
	}
	tmp = ft_wstrsubpf(*w, t->precision);
	*w = tmp;
}
