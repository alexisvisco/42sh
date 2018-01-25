/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 14:24:17 by aviscogl    ###    #+. /#+    ###.fr     */
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

typedef struct termios	t_termios;


typedef enum	e_mode {
	INSERTION,
	COMPLETION,
	HISTORY_SEARCH
}				t_mode;

enum	e_key_action
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
	CTRL_O = 15,
	CTRL_I = 9,
	CTRL_L = 12,
	ENTER = 13,
	CTRL_N = 14,
	CTRL_P = 16,
	CTRL_T = 20,
	CTRL_U = 21,
	CTRL_W = 23,
	ESC = 27,
	BACKSPACE = 127,
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

typedef struct	s_refresher
{
	char		seq[64];
	int			plen;
	int			rows;
	int			rpos;
	int			rpos2;
	int			col;
	int			old_rows;
}				t_refresher;

typedef struct	s_buf
{
	char		*b;
	int			len;
}				t_buf;

typedef struct	s_history
{
	t_heap		*heap;
	char		origin[EDITOR_MAX_LINE];
	int64_t		index;
}				t_history;

typedef void(t_redirect_fn)(t_editor *);

extern t_termios	g_origin;
extern int			g_raw_mode;


char			*readline(const char *prompt);
char			*readline_notty();
int				readline_raw(char *buf, const char *prompt);

int				handle_keys(t_editor *e);
void			redirect_key_fn(t_editor *e, char c, char *seq);
int				editor(int stdin_fd, int stdout_fd, char *buf,
char *prompt);
void			editor_insert(t_editor *l, char c);
void			editor_insert_without_refresh(t_editor *l, char c);

int				enable_terminal(int fd);
int				disable_terminal(int fd);

void			buf_append(t_buf *ab, const char *s, int len);
void			refresh_line(t_editor *e);
void			clear_used_before(t_refresher *r, t_buf *b);
void			clear_and_go_up(t_refresher *r, t_buf *b);
void			clean_top_show_prompt(t_editor *e, t_buf *b);
void			insert_new_line(t_editor *e, t_refresher *r, t_buf *b);
void			move_cursor(t_editor *e, t_refresher *r, t_buf *b);
void			set_colum(t_editor *e, t_refresher *r, t_buf *b);

int				get_cursor_pos(int ifd, int ofd);
int				get_colums_len(int ifd, int ofd);

t_history		*get_history();
void			history_up(t_editor *e);
void			history_down(t_editor *e);
void			history_add(t_editor *e);
void			set_origin(t_editor *e);
void			origin_to_buf(t_editor *e);

void			ef_clear_screen(t_editor *l);
void			ef_del_prev_word(t_editor *l);
void			ef_delete_curr_to_end(t_editor *l);
void			ef_delete_entire_line(t_editor *l);
void			ef_go_end(t_editor *l);
void			ef_go_home(t_editor *l);
void			ef_move_up(t_editor *l);
void			ef_move_down(t_editor *l);
void			ef_move_left(t_editor *l);
void			ef_move_right(t_editor *l);
void			ef_swap_char(t_editor *l);
void			ef_del_backspace(t_editor *e);
void			ef_del_simple(t_editor *l);

#endif
