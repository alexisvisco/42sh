/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readline.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 18:19:20 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 10:32:58 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"


static t_termios	g_origin;
static int			raw_mode;

static int unsupported_term(void)
{
	static char	*unsupported_term[] = {"dumb","cons25","emacs",NULL};
    //TODO : search in environement variable TERM equal to a term ^.
    return 0;
}

char	*readline(const char *prompt, int fd)
{
	char	buf[EDITOR_MAX_LINE];
    int		count;

	if (!isatty(STDIN_FILENO))
		return readline_notty();
	if (unsupported_term())
	{
		ft_putstr_fd(stderr, "Shell: unsuported terminal.");
		exit(2);
	}
	else
	{
		count = linenoiseRaw(buf, EDITOR_MAX_LINE, prompt);
        if (count == -1)
			return (NULL);
        return (strdup(buf));
	}
}