/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   number_precision.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/27 11:41:09 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	number_precision(t_formatter *t)
{
	char	*str;
	char	*pad;
	int		diff;

	diff = t->precision - (ft_strlen(t->to_replace) - (t->type == 'p' ? 2 : 0));
	if (t->to_replace[0] == '-')
		diff++;
	if (ft_strchr(t->flags, '#') && (t->type == 'x' || t->type == 'X'))
		diff += 2;
	if (diff <= 0)
		return ;
	pad = ft_str_repeatm('0', diff);
	if ('p' == t->type && ft_strequ(t->to_replace, "0"))
		str = ft_strdup("0x");
	else if (!ft_strchr(t->flags, '#') && !(t->type == 'p'))
		str = ft_strappend_at(t->to_replace[0] == '-' ?
		1 : 0, t->to_replace, pad);
	else
		str = ft_strappend_at(ft_strchr("xXp", t->type) ?
		2 : 1, t->to_replace, pad);
	ft_memdel((void **)&(t->to_replace));
	ft_memdel((void **)&pad);
	t->to_replace = str;
}
