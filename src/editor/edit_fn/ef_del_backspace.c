/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_del_backspace.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 15:23:51 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:22:57 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Delete the previous character
*/

void	ef_del_backspace(t_editor *l)
{
	if (l->pos > 0 && l->len > 0)
	{
		ft_memmove(l->buf + l->pos - 1, l->buf + l->pos, l->len - l->pos);
		l->pos--;
		l->len--;
		l->buf[l->len] = '\0';
	}
}

/*
** Delete the previous character x times
*/

void	ef_del_backspace_times(t_editor *l, unsigned int x)
{
	unsigned int i;

	i = 0;
	while (i < x)
	{
		ef_del_backspace(l);
		i++;
	}
}
