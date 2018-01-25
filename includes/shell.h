/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 13:06:19 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# define SHELL_NAME "./shell"

# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <termcap.h>
# include <term.h>
# include <termios.h>
# include <dirent.h>
# include <signal.h>
# include <stdint.h>
# include "editor.h"
# include "lex.h"
# include "libft.h"

typedef enum	e_message{
	ERR_NOTHING_ENTERED,
	ERR_CTRL_C,
	ERR_CMD_NOT_FOUND,
	ERR_EXE_CMD,
	SHELL_EXIT,
	ERR_PWD_NOT_FOUND,
	ERR_SETENV_FORMAT,
	ERR_SETENV_CMD,
	ERR_UNENV_CMD
}				t_message;

typedef enum	e_parse{
	ERR_QUOTE,
	ERR_REDIR,
	ERR_PIPE,
	ERR_AFTER_FD
}				t_eparse;

void		e_general(t_message m, char *arg);
void		e_parse(t_eparse m, char *arg);

#endif
