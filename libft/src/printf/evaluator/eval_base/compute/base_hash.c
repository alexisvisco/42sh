/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   base_hash.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/27 10:51:33 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 12:14:35 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	base_hash(t_formatter *t)
{
	char	*str;
	int		can_apply;

	can_apply = ft_strlen(t->to_replace) > 0 && !ft_strequ(t->to_replace, "0");
	if (can_apply || 'p' == t->type)
	{
		if ('p' == t->type && ft_strequ(t->to_replace, "0")
		&& (ft_strchr(t->flags, '#') || t->precision == 0))
			str = ft_strdup("0x");
		else if (ft_strchr("xXp", t->type))
			str = ft_strappend_at(0, t->to_replace, t->type == 'X' ? "0X" :
			"0x");
		else if (ft_strchr("o", t->type) || ft_strchr("O", t->type))
			str = ft_strappend_at(0, t->to_replace, "0");
		else
			return ;
		free(t->to_replace);
		t->to_replace = str;
	}
}
