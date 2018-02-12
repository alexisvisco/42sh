/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   refresh_line.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 13:23:45 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 09:27:53 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

static void	init_refresh(t_editor *e, t_refresher *r)
{
	r->plen = (int)e->plen;
	r->rows = (int)((r->plen + e->len + e->cols - 1) / e->cols);
	r->rpos = (int)((r->plen + e->oldpos + e->cols) / e->cols);
	r->old_rows = (int)e->maxrows;
}

static void	init_buf(t_buf *buf)
{
	buf->b = NULL;
	buf->len = 0;
}

/*
** Rewrite the currently edited line accordingly to the buffer content,
** cursor position, and number of columns of the terminal.
*/

void		refresh_line(t_editor *e)
{
	t_refresher	ref;
	t_buf		buf;

	init_refresh(e, &ref);
	init_buf(&buf);
	if (ref.rows > (int)e->maxrows)
		e->maxrows = (size_t)ref.rows;
	clear_used_before(&ref, &buf);
	clear_and_go_up(&ref, &buf);
	clean_top_show_prompt(e, &buf);
	insert_new_line(e, &ref, &buf);
	move_cursor(e, &ref, &buf);
	set_colum(e, &ref, &buf);
	write(e->ofd, buf.b, (size_t)buf.len);
	free(buf.b);
}
