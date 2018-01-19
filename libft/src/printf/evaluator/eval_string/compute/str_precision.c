/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_precision.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 15:09:08 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/02 13:36:45 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_precision(t_formatter *t)
{
	char *tmp;

	tmp = ft_strsub(t->to_replace, 0, (size_t)t->precision);
	free(t->to_replace);
	t->to_replace = tmp;
}
