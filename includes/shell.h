/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 12:36:20 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define SHELL_NAME "21sh"
# define HISTORY_FILE ".21sh_history"

# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <termcap.h>
# include <termios.h>
# include <term.h>
# include <signal.h>
# include <stdint.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include "libft.h"
# include "shell_struct.h"
# include "editor.h"
# include "lex.h"
# include "exec.h"
# include "util.h"
# include "builtins.h"
# include "variables.h"

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
	ERR_NO_OLD_PWD,

	ERR_HISTORY_ARG_MERGED,
	MSG_HISTORY_CLEARED,
	ERR_HISTORY_OFFSET_NEEDED,
	ERR_HISTORY_OFFSET_INVALID,
	MSG_HISTORY_DELETED,
	MSG_HISTORY_APPENDED,
	ERR_HISTORY_APPENDED,
	ERR_HISTORY_NON_READ,
	MSG_HISTORY_NON_READ,
	ERR_HISTORY_READ,
	MSG_HISTORY_READ,
	ERR_HISTORY_WRITE,
	MSG_HISTORY_WRITE,

	ERR_VAR_USAGE,
	ERR_VAR_NOT_EXIST,
	MSG_VAR_EXPORTED,
	MSG_VAR_UNSETED,
	MSG_VAR_TYPEOF,
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
void			set_vars(void);
void			init_shell(char **env);

#endif
