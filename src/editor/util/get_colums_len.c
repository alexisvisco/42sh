/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_colums_len.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 15:21:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Try to get the number of columns in the current terminal, or assume 80
** if it fails.
*/

int		get_colums_len(int ifd, int ofd)
{
	struct winsize	ws;
	int				start;
	int				cols;
	char			*tmp;

	if (ioctl(1, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0)
	{
		start = get_cursor_pos(ifd, ofd);
		if (start == -1)
			return (80);
		if (write(ofd, "\x1b[999C", 6) != 6)
			return (80);
		cols = get_cursor_pos(ifd, ofd);
		if (cols == -1)
			return (80);
		tmp = ft_sprintf("\x1b[%dD", cols - start);
		ft_putstr_fd(ofd, tmp);
		free(tmp);
		return (cols);
	}
	else
		return (ws.ws_col);
}
