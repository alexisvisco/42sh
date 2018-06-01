/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   str_padding.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/23 15:11:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_padding(t_formatter *t)
{
	int		is_left;
	int		diff;
	char	*to_add;
	char	*ret;

	is_left = ft_strchr(t->flags, '-') != NULL;
	diff = t->width - ft_strlen(t->to_replace);
	if (diff <= 0)
		return ;
	to_add = (char *)ft_memalloc(sizeof(char) * (diff + 1));
	to_add[diff] = 0;
	ft_str_repeat(&to_add, ' ', diff);
	ret = ft_strappend_at(is_left ? ft_strlen(t->to_replace) : 0,
	t->to_replace, to_add);
	ft_memdel((void **)&to_add);
	ft_memdel((void **)&(t->to_replace));
	t->to_replace = ret;
}
