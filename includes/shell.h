/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 10:47:31 by ggranjon    ###    #+. /#+    ###.fr     */
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
# include "lex.h"
# include "exec.h"
# include "shell_struct.h"
# include "builtins.h"

extern t_shell	g_shell;

typedef enum	e_message
{
	ERR_NOTHING_ENTERED,
	ERR_CTRL_C,
	ERR_CMD_NOT_FOUND,
	ERR_EXE_CMD,
	TERM_ENV_NOT_SET,
}				t_message;

typedef enum	e_msg_builtins
{
	ERR_PWD_NOT_FOUND,
	ERR_SETENV_FORMAT,
	MSG_SETENV,
	ERR_UNSETENV_FORMAT,
	ERR_UNSETENV_NOT_EXIST,
	MSG_UNSETENV,
	SHELL_EXIT,
	ERR_BIN_SEARCH_FORMAT,
	MSG_SEARCH_BIN_FOUND,
	ERR_NO_HISTORY,
	ERR_CD,
	ERR_CD_ACCESS,
	ERR_CD_DIR,
	MSG_CD,
	ERR_NO_HISTORY_AVAILABLE,
	ERR_NO_HISTORY_THAT_CONTAIN,
	ERR_NO_HISTORY_THAT_START,
	ERR_NO_HISTORY_FROM_BEGIN,
	ERR_NO_HISTORY_FROM_END,
}				t_msg_builtins;

typedef enum	e_parse
{
	ERR_QUOTE,
	ERR_REDIR,
	ERR_PIPE,
	ERR_AFTER_FD,
	ERR_BAD_END,
	ERR_ONLY_COMMENT,
	ERR_SEMICOL
}				t_eparse;

typedef enum	e_editor
{
	ERR_UNRECOGNIZED_TERM
}				t_eeditor;

typedef enum	e_open
{
	ERR_IS_DIR,
	ERR_PERM,
	ERR_ACCES,
	ERR_EXIST
}				t_eopen;

void			e_general(t_message m, char *arg);
void			e_parse(t_eparse m, char *arg);
void			e_open(t_eopen m, char *arg);
void			e_editor(t_eeditor m, char *arg);
void            err_builtins(t_msg_builtins m, ...);
void            msg_builtins(t_msg_builtins m, ...);

void			set_env();
void			set_bin(t_shell *shell);
void            update_bin(t_shell *shell);
void			set_builtins(void);
void			set_options();
void			exit_shell();
void			init_shell();

#endif
