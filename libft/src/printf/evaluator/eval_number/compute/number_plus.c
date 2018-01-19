/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   number_plus.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/28 10:57:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/03 15:27:50 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	number_plus(t_formatter *t)
{
	char *str;

	if (t->to_replace[0] == '-')
		return ;
	str = ft_strappend_at(0, t->to_replace, "+");
	free(t->to_replace);
	t->to_replace = str;
}
