/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_cursor_pos.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 15:11:47 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Use the ESC [6n escape sequence to query the horizontal cursor position
** and return it. On error -1 is returned, on success the position of the
** cursor.
*/

int		get_cursor_pos(int ifd, int ofd)
{
	char			buf[32];
	unsigned int	i;

	i = 0;
	if (write(ofd, "\x1b[6n", 4) != 4)
		return (-1);
	while (i < sizeof(buf) - 1)
	{
		if (read(ifd, buf + i, 1) != 1)
			break ;
		if (buf[i] == 'R')
			break ;
		i++;
	}
	buf[i] = '\0';
	if (buf[0] != ESC || buf[1] != '[')
		return (-1);
	i = 0;
	while (buf[i] && buf[i] != ';')
		i++;
	i++;
	return (ft_atoi((buf + i)));
}
