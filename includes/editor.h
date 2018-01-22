/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 11:35:04 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "libft.h"
# include "util.h"
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

typedef enum	e_mode {
	INSERTION,
	COMPLETION,
	HISTORY_SEARCH
}				t_mode;

enum e_key_action
{
	KEY_NULL = 0,
	KON = 35051931,
	CTRL_A = 1,
	CTRL_B = 2,
	CTRL_C = 3,
	CTRL_D = 4,
	CTRL_E = 5,
	CTRL_F = 6,
	CTRL_H = 8,
	TAB = 9,
	CTRL_K = 11,
	CTRL_L = 12,
	ENTER = 13,
	CTRL_N = 14,
	CTRL_P = 16,
	CTRL_T = 20,
	CTRL_U = 21,
	CTRL_W = 23,
	ESC = 27,
	BACKSPACE = 127,
	UP_ARROW = 4283163,
	DOWN_ARROW = 4348699,
	LEFT_ARROW = 4479771,
	RIGHT_ARROW = 4414235,
	HOME = 4741915,
	END = 4610843,
};

typedef struct	s_editor
{
	int			ifd;
	int			ofd;
	t_termios	origin;
	char		*buf;
	size_t		buflen;
	const char	*prompt;
	size_t		plen;
	size_t		pos;
	size_t		oldpos;
	size_t		len;
	size_t		cols;
	size_t		maxrows;
	int			history_index;
	t_mode		mode;
}				t_editor;


extern t_termios	g_origin;
extern int			raw_mode;

char			*readline(const char *prompt, int fd);
char			*readline_notty();
int				readline_raw(char *buf, size_t buflen, const char *prompt);

void			handle_keys(t_editor *e);
int				editor(int stdin_fd, int stdout_fd, char *buf, size_t buflen,
const char *prompt);

int				enable_terminal(int fd);
int				disable_terminal(int fd);

int				get_cursor_pos(int ifd, int ofd);
int				get_colums_len(int ifd, int ofd);


#endif