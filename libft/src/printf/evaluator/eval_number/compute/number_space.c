/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   number_space.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/28 10:59:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	number_space(t_formatter *t)
{
	char *str;

	if (t->to_replace[0] == '-' || t->to_replace[0] == '+')
		return ;
	str = ft_strappend_atc(0, t->to_replace, ' ');
	ft_memdel((void **)&(t->to_replace));
	t->to_replace = str;
}
