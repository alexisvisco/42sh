/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 10:35:37 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 21:15:54 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

static void		init_editor(t_editor *editor)
{
	editor->pos = 0;
	editor->len = 0;
	editor->oldpos = 0;
	editor->cols = get_colums_len(editor->ifd, editor->ofd);
	editor->maxrows = 0;
	editor->history_index = 0;
}

/*
** This function is the core of the line editing capability of readline.
** It expects 'fd' to be already in "raw mode" so that every key pressed
** will be returned ASAP to read().
**
** The resulting string is put into 'buf' when the user type enter, or
** when ctrl+d is typed.
**
** The function returns the length of the current buffer.
*/

int				editor(int stdin_fd, int stdout_fd, char *buf, size_t buflen,
char *prompt)
{
	t_editor l;

	l.ifd = stdin_fd;
    l.ofd = stdout_fd;
	l.buf = buf;
	l.buflen = buflen;
	l.prompt = ft_strdup(prompt);
	l.plen = ft_strlen(prompt);
	// ft_printf("len %zu\n", editor->len);
	init_editor(&l);
	ft_putstr_fd(l.ofd, l.prompt);
	handle_keys(&l);
	return (0);
}
