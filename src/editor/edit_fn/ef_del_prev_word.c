/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_del_prev_word.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:31:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 13:26:21 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Delete if possible the previous word
*/

void	ef_del_prev_word(t_editor *l)
{
	size_t old_pos;
	size_t diff;

	old_pos = l->pos;
	while (l->pos > 0 && l->buf[l->pos - 1] == ' ')
		l->pos--;
	while (l->pos > 0 && l->buf[l->pos - 1] != ' ')
		l->pos--;
	diff = old_pos - l->pos;
	ft_memmove(l->buf + l->pos, l->buf + old_pos, l->len - old_pos + 1);
	l->len -= diff;
}
