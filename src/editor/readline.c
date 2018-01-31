/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readline.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/20 18:19:20 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 20:17:28 by aviscogl    ###    #+. /#+    ###.fr     */
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
	char		*term;
	int			i;

	term = ht_get(g_shell.env, "TERM");
	if (!term)
		return (1);
	i = -1;
	while (unsupported_term[++i])
		if (ft_strequ(unsupported_term[i], term))
			return (1);
	return (0);
}

/*
** This function checks if the terminal has basic capabilities, just checking
** for a blacklist of fucking stupid terminals, and later either calls
** the line editing function.
**
** Then return the line typed in the terminal.
*/

char		*readline(const char *prompt, t_options *e)
{
	char	buf[EDITOR_MAX_LINE];
	int		count;

	if (!isatty(STDIN_FILENO))
		return (readline_notty());
	if (unsupported_term())
	{
		e_editor(ERR_UNRECOGNIZED_TERM, NULL);
		exit_shell();
		exit(2);
	}
	else
	{
		count = readline_raw(buf, prompt, e);
		if (count == -1)
			return (NULL);
		return (strdup(buf));
	}
}
