/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 10:33:08 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include <termios.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <unistd.h>

# define EDITOR_DEFAULT_HISTORY_MAX_LEN 100
# define EDITOR_MAX_LINE 4096

typedef struct termios t_termios;

typedef struct	s_editor
{
	t_termios	origin;
	char		*buf;
	size_t		buf_len;
	const char	*prompt;
	size_t		plen;
	size_t		pos;
	size_t		len;
	size_t		cols;
	size_t		maxrows;
	int			history_index;
	t_mode		mode;
}				t_editor;

typedef enum	e_mode {
	INSERTION,
	COMPLETION,
	HISTORY_SEARCH
}				t_mode;

extern t_termios	g_origin;
extern int			raw_mode;

char			*readline(const char *prompt, int fd);
char			*readline_notty();

int				enable_terminal(int fd);

#endif