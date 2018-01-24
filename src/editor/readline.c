/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readline.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 18:19:20 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 14:00:07 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"


t_termios	g_origin;
int			g_raw_mode;

/*
** Check if the terminal in the env TERM is
** supported. If not return 1.
** Else if term is supported return 0.
*/

static int	unsupported_term(void)
{
	static char	*unsupported_term[] = {"dumb", "cons25", "emacs", NULL};

	//TODO : search in environement variable TERM equal to a term ^.
	return (0);
}

/*
** This function checks if the terminal has basic capabilities, just checking
** for a blacklist of fucking stupid terminals, and later either calls
** the line editing function.
**
** Then return the line typed in the terminal.
*/

char		*readline(const char *prompt, int fd)
{
	char	buf[EDITOR_MAX_LINE];
	int		count;

	if (!isatty(STDIN_FILENO))
		return (readline_notty());
	if (unsupported_term())
	{
		ft_putstr_fd(STDERR_FILENO, "Shell: unsuported terminal.");
		exit(2);
	}
	else
	{
		count = readline_raw(buf, prompt);
		if (count == -1)
			return (NULL);
		return (strdup(buf));
	}
}
