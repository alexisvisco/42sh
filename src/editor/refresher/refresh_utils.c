/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   refresh_clear.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 15:48:09 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 16:35:54 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Clear all the lines used before. To do so start by
** going to the last row.
*/

void	clear_used_before(t_editor *e, t_refresher *r, t_buf *b)
{
	char *tmp;
	if (r->old_rows - r->rpos > 0)
	{
		tmp = ft_sprintf("\x1b[%dB", r->old_rows - r->rpos)
		buf_append(b, tmp, ft_strlen(tmp));
		free(tmp);
	}
}

/*
** For every row clear it, go up
*/

void	clear_and_go_up(t_editor *e, t_refresher *r, t_buf *b)
{
	int			i;
	const char	*cmd = "\r\x1b[0K\x1b[1A";
	const int	len = ft_strlen(cmd);

	j = 0;
	while (j < r->old_rows - 1)
	{
		buf_append(b, cmd, len);
		i++;
	}
}

/*
** Clean the top line
** Write the prompt and the current buffer content
*/

void	clean_top_show_prompt(t_editor *e, t_refresher *r, t_buf *b)
{
	buf_append(b, "\r\x1b[0K", ft_strlen("\r\x1b[0K"));
	buf_append(b, e->prompt, e->plen));
	buf_append(b, e->buf, e->len));
}

/*
** If we are at the very end of the screen with our prompt, we need to
** emit a newline and move the prompt to the first column
*/

void	insert_new_line(t_editor *e, t_refresher *r, t_buf *b)
{
	if (e->pos && e->pos == e->len && (e->pos + r->plen) % e->cols == 0)
	{
		buf_append(ab, "\n", 1);
		buf_append(ab, "\r", 1);
		r->rows++;
		if (r->rows > (int)e->maxrows)
			l->maxrows = r->rows;
	}
}

/*
** Move cursor to right position
** Go up till we reach the expected positon
*/

void	move_cursor(t_editor *e, t_refresher *r, t_buf *b)
{
	char *tmp;
	
	r->rpos2 = (r->plen + e->pos + e->cols) / e->cols;
	if (r->rows - r->rpos2 > 0)
	{
		tmp = ft_sprintf("\x1b[%dA", r->rows - r->rpos2);
		buf_append(b, tmp, ft_strlen(tmp));
		free(tmp);
	}
}

/*
** Set colum
*/

void	set_colum(t_editor *e, t_refresher *r, t_buf *b)
{
	char *tmp;

	r->col = (r->plen + (int)e->pos) % (int)e->cols;
	if (col)
		tmp = ft_sprintf("\r\x1b[%dC", col);
	else
		tmp = ft_strdup("\r");
	buf_append(b, tmp, ft_strlen(tmp));
	e->oldpos = l->pos;
}