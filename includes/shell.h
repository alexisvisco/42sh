/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 21:28:21 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define SHELL_NAME "shell"

# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <stdint.h>
# include <sys/types.h>
# include <dirent.h>
# include "libft.h"
# include <sys/stat.h>
# include "editor.h"
# include "builtins.h"
# include "lex.h"
# include "exec.h"


typedef enum	e_message
{
	ERR_NOTHING_ENTERED,
	ERR_CTRL_C,
	ERR_CMD_NOT_FOUND,
	ERR_EXE_CMD,
	SHELL_EXIT,
	TERM_ENV_NOT_SET,
}				t_message;

typedef enum    e_msg_builtins
{
	ERR_PWD_NOT_FOUND,
	ERR_SETENV_FORMAT,
	MSG_SETENV,
	ERR_UNSETENV_FORMAT,
	ERR_UNSETENV_NOT_EXIST,
	MSG_UNSETENV,
}               t_msg_builtins;

typedef enum	e_parse
{
	ERR_QUOTE,
	ERR_REDIR,
	ERR_PIPE,
	ERR_AFTER_FD,
	ERR_BAD_END,
	ERR_ONLY_COMMENT
}				t_eparse;

typedef enum	e_editor
{
	ERR_UNRECOGNIZED_TERM
}				t_eeditor;


typedef struct	s_shell
{
	t_hashtable	*env;
	t_hashtable	*bin;
	t_trie_node	*bin_trie;
	t_trie_node	*env_trie;
	t_options	*line_edit;
	t_options	*history_search;
}				t_shell;

extern t_shell	g_shell;

typedef enum	e_open
{
	ERR_IS_DIR,
	ERR_PERM,
	ERR_EXIST
}				t_eopen;

void			e_general(t_message m, char *arg);
void			e_parse(t_eparse m, char *arg);
void			e_open(t_eopen m, char *arg);
void			e_editor(t_eeditor m, char *arg);
void            err_builtins(t_msg_builtins m, ...);
void            msg_builtins(t_msg_builtins m, ...);

void			set_env();
void			set_bin();
void            update_bin();
void			set_options();
void			exit_shell();
void			init_shell();

#endif
