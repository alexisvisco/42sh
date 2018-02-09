/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move_cursor.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 12:59:21 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 12:41:42 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Move cursor to right position
** Go up till we reach the expected positon
*/

void	move_cursor(t_editor *e, t_refresher *r, t_buf *b)
{
	char *tmp;

	r->rpos2 = (int)((r->plen + e->pos + e->cols) / e->cols);
	if (r->rows - r->rpos2 > 0)
	{
		tmp = ft_sprintf("\x1b[%dA", r->rows - r->rpos2);
		buf_append(b, tmp, (int)ft_strlen(tmp));
		free(tmp);
	}
}
