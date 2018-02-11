/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/11 17:29:50 by ggranjon    ###    #+. /#+    ###.fr     */
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
# include "shell_struct.h"
# include "editor.h"
# include "lex.h"
# include "exec.h"
# include "util.h"
# include "builtins.h"

extern t_shell	g_shell;

typedef enum	e_msgs
{
	ERR_CMD_NOT_FOUND,
	ERR_NOTHING_ENTERED,
	ERR_EXE_CMD,
	TERM_ENV_NOT_SET,

	ERR_REDIR,
	ERR_QUOTE,
	ERR_PIPE,
	ERR_AFTER_FD,
	ERR_BAD_END,
	ERR_ONLY_COMMENT,
	ERR_SYNTAX_NEAR_TOKEN,

	ERR_IS_DIR,
	ERR_ACCES,
	ERR_EXIST,
	ERR_PERM,

	ERR_UNRECOGNIZED_TERM,
	ERR_UNSUPORTED_OPERATION,

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
	ERR_NO_OLD_PWD
}				t_msgs;

int				shell_process(char *s);

void			message(t_msgs m, ...);
void			message_err(t_msgs m, ...);
void			message_fd(int fd, t_msgs m, ...);

void			set_env(char **env);
void			set_bin(t_shell *shell);
void			update_bin(t_shell *shell);
void			set_builtins(void);
void			set_options();
void			exit_shell();
void			init_shell(char **env);

#endif
