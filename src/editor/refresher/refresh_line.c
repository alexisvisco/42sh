/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   refresh_line.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 13:23:45 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 16:51:46 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

static void	init_refresh(t_editor *e, t_refresher *r)
{
	r->plen = e->plen;
	r->rows = (r->plen + e->len + e->cols - 1) / e->cols;
	r->rpos = (r->plen + e->oldpos + e->cols) / e->cols;
	r->old_rows = e->maxrows;
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

void	refresh_line(t_editor *e)
{
	t_refresher	ref;
	t_buf		buf;

	init_refresh(&ref);
	init_buf(&buf)
	if (ref->rows > (int)e->maxrows)
		e->maxrows = ref->rows;
	clear_used_before(e, ref, buf);
	clear_and_go_up(e, ref, buf);
	clean_top_show_prompt(e, ref, buf);
	insert_new_line(e, ref, buf);
	move_cursor(e, ref, buf);
	set_colum(e, ref, buf);
	ft_putstr_fd(e->ofd, buf.b);
	free(buf.b);
}