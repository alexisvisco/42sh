/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   insert_new_line.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/25 12:58:33 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 13:51:59 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** If we are at the very end of the screen with our prompt, we need to
** emit a newline and move the prompt to the first column
*/

void	insert_new_line(t_editor *e, t_refresher *r, t_buf *b)
{
	if (e->pos && e->pos == e->len && (e->pos + r->plen) % e->cols == 0)
	{
		buf_append(b, "\n", 1);
		buf_append(b, "\r", 1);
		r->rows++;
		if (r->rows > (int)e->maxrows)
			e->maxrows = (size_t)r->rows;
	}
}
