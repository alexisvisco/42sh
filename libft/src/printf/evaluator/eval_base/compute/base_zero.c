/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   base_zero.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/27 11:01:09 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	base_zero(t_formatter *t)
{
	char	*str;
	char	*pad;
	int		diff;

	diff = t->width - ft_strlen(t->to_replace);
	if (diff <= 0)
		return ;
	pad = ft_str_repeatm('0', diff);
	if (!ft_strchr(t->flags, '#') && !(t->type == 'p'))
		str = ft_strappend_at(0, t->to_replace, pad);
	else
		str = ft_strappend_at(ft_strchr(BASE_SX, t->type) ||
		t->type == 'p' ? 2 : 1,
		t->to_replace, pad);
	ft_memdel((void **)&(t->to_replace));
	ft_memdel((void **)&pad);
	t->to_replace = str;
}
