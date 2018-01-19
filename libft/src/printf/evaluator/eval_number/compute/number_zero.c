/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   number_zero.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/27 11:01:09 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/04 11:10:00 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	number_zero(t_formatter *t)
{
	char	*str;
	char	*pad;
	int		diff;

	diff = t->width - ft_strlen(t->to_replace);
	if ((ft_strchr(t->flags, '+') || ft_strchr(t->flags, ' ')) &&
	t->to_replace[0] != '-')
		diff -= diff == 0 ? 0 : 1;
	if (diff <= 0)
		return ;
	pad = ft_str_repeatm('0', diff);
	str = ft_strappend_at(t->to_replace[0] == '-' ? 1 : 0, t->to_replace, pad);
	free(t->to_replace);
	free(pad);
	t->to_replace = str;
}
