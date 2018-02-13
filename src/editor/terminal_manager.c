/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   terminal_manager.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 10:25:20 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 15:39:40 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Enable raw mode terminal :
** - input modes: no break, no CR to NL, no parity check, no strip char,
**   no start/stop output control.
** - output modes - disable post processing.
** - control modes - set 8 bit chars.
** - local modes - choing off, canonical off, no extended functions,
**   no signal chars (^Z,^C).
** - control chars - set return condition: min number of bytes and timer.
**
** We want read to return every single byte, without timeout.
*/

int		enable_terminal(int fd)
{
	t_termios raw;

	if (!isatty(STDIN_FILENO))
		return (-1);
	if (tcgetattr(fd, &g_origin) == -1)
		return (-1);
	raw = g_origin;
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 0;
	if (tcsetattr(fd, TCSAFLUSH, &raw) < 0)
		return (-1);
	return (1);
}

/*
** Disable raw terminal.
*/

int		disable_terminal(int fd)
{
	tcsetattr(fd, TCSAFLUSH, &g_origin);
	return (1);
}
