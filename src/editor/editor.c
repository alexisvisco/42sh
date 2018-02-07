/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 10:35:37 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 11:04:06 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <shell.h>

static void		init_editor(t_editor *editor)
{
	editor->pos = 0;
	editor->len = 0;
	editor->oldpos = 0;
	editor->cols = (size_t)get_colums_len(editor->ifd, editor->ofd);
	editor->maxrows = 0;
	editor->buflen = EDITOR_MAX_LINE;
	editor->plen = ft_strlen(editor->prompt);
	editor->buf[0] = 0;
	init_history(editor);
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

int				editor(char *buf, char *prompt, t_options *opt)
{
	t_editor l;

	l.ifd = STDIN_FILENO;
	l.ofd = STDOUT_FILENO;
	l.buf = buf;
	l.prompt = prompt;
	l.options = opt;
	init_editor(&l);
	ft_putstr_fd(l.ofd, l.prompt);
	editor_insert_str(&l, g_shell.line_edit->next_line);
	g_shell.line_edit->next_line[0] = 0;
	return (handle_keys(&l));
}
