/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
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
# include <dirent.h>
# include <stdlib.h>
# include <ctype.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <unistd.h>

# define EDITOR_MAX_LINE 4096

# define HISTORY_DATA g_shell.line_edit->history_data->heap

typedef struct termios	t_termios;

typedef enum		e_mode {
	INSERTION,
	COMPLETION,
	HISTORY_SEARCH
}					t_mode;

enum				e_key_action
{
	CTRL_A = 1,
	CTRL_B = 2,
	CTRL_C = 3,
	CTRL_V = 22,
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

typedef struct		s_refresher
{
	int			plen;
	int			rows;
	int			rpos;
	int			rpos2;
	int			col;
	int			old_rows;
}					t_refresher;

typedef struct		s_buf
{
	char		*b;
	int			len;
}					t_buf;

typedef struct		s_edit_content
{
	t_heap		*heap;
	char		origin[EDITOR_MAX_LINE];
	int64_t		index;
	int			plus;
}					t_e_content;

typedef struct		s_options
{
	int			has_completion;
	int			has_history;
	t_e_content	*history_data;
	t_e_content	*completion_data;
	char		next_line[EDITOR_MAX_LINE];
	int			can_load_history;
	int			can_ctrl_d;
}					t_options;

typedef struct		s_editor
{
	int			ifd;
	int			ofd;
	char		*buf;
	size_t		buflen;
	const char	*prompt;
	size_t		plen;
	size_t		pos;
	size_t		oldpos;
	size_t		len;
	size_t		cols;
	size_t		maxrows;
	t_mode		mode;
	t_options	*options;
}					t_editor;

typedef enum		e_cp_type
{
	TYPE_COMMAND,
	TYPE_PATH,
	TYPE_ENV
}					t_cp_type;

typedef struct		s_word_info
{
	t_cp_type	type;
	char		*current_word;
	size_t		begin;
	size_t		end;
}					t_word_info;

typedef void(t_redirect_fn)(t_editor *);

extern t_termios	g_origin;

void				deb_printer(const char *format, ...);
void				free_options(t_options *t);

char				*readline(char *prompt, t_options *opt);
char				*readline_notty();
int				readline_raw(char *buf, char *prompt, t_options *e);
void				init_editor(t_editor *editor, char *buf, const char *prompt,
							t_options *opt);
int				handle_keys(t_editor *e);
void				redirect_key_fn(t_editor *e, char c, char *seq);
int				redirect_control_key(t_editor *e, char c);
int				editor(char *buf, char *prompt, t_options *opt);
void				editor_insert(t_editor *l, char c);
void				editor_insert_instant(t_editor *l, char c);
void				editor_insert_without_refresh(t_editor *l, char c);
void				editor_insert_str(t_editor *l, char *str);
void				editor_insert_str_without_refresh(t_editor *l, char *str);

int				enable_terminal(int fd);
int				disable_terminal(int fd);

void				buf_append(t_buf *ab, const char *s, int len);
void				refresh_line(t_editor *e);
void				clear_used_before(t_refresher *r, t_buf *b);
void				clear_and_go_up(t_refresher *r, t_buf *b);
void				clean_top_show_prompt(t_editor *e, t_buf *b);
void				insert_new_line(t_editor *e, t_refresher *r, t_buf *b);
void				move_cursor(t_editor *e, t_refresher *r, t_buf *b);
void				set_colum(t_editor *e, t_refresher *r, t_buf *b);

int					get_cursor_pos(int ifd, int ofd);
int					get_colums_len(int ifd, int ofd);

void				get_previous_history(t_heap *h);
int					rewrite_history_file(t_heap *h);
int					rewrite_history_file_in(t_heap *h, const char *path,
											   int from);
void				init_history(t_editor *e);
void				history_search(t_editor *e);
void				history_up(t_editor *e);
void				history_down(t_editor *e);
void				history_add(t_editor *e);
void				set_origin(t_editor *e);
void				origin_to_buf(t_editor *e);
void				history_search_msg(void);
void				prepare_history(t_editor *e);

void				completion_next(t_editor *e);
void				completion_printer(t_editor *e, t_heap *list);
void				completion_handler(t_editor *e);
void				completion_delete(t_editor *e);
void				init_completion(t_editor *e);
void				get_word_at(char *cmd, size_t position, t_word_info *w);
void				get_completions(t_editor *e);
void				get_completions_bin(t_word_info *i, t_heap *h);
void				get_completions_env(t_word_info *i, t_heap *h);
void				get_completions_path(t_word_info *i, t_heap *h);
char				*get_folder_from(char *str);
char				*get_name_from(char *str);
void				set_word_info(t_word_info *i, t_editor *e);
void				update_word(t_editor *e, char *word);
int					word_is_command(t_word_info *i, t_word_info *prev);
int					word_is_path(t_word_info *i);
int					word_is_env(t_word_info *i);
void				free_e_content(t_e_content *h);

void				ef_clear_screen(t_editor *l);
void				ef_move_word_right(t_editor *e);
void				ef_move_word_left(t_editor *e);
void				ef_del_prev_word(t_editor *l);
void				ef_delete_curr_to_end(t_editor *l);
void				ef_delete_entire_line(t_editor *l);
void				ef_go_end(t_editor *l);
void				ef_go_home(t_editor *l);
void				ef_move_cursor_to(t_editor *e, size_t position);
void				ef_move_up(t_editor *l);
void				ef_move_down(t_editor *l);
void				ef_move_left(t_editor *l);
void				ef_move_right(t_editor *l);
void				ef_swap_char(t_editor *l);
void				ef_del_backspace(t_editor *e);
void				ef_del_backspace_times(t_editor *l, unsigned int x);
void				ef_del_simple(t_editor *l);
void				ef_paste_clipboard(t_editor *l);

#endif
