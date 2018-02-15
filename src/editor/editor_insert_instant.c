/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor_insert_instant.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 18:31:32 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 12:08:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <editor.h>

/*
** Insert the character 'c' at cursor current position
** If we are at the end of the line just append the character with a putchar but
** if the character need to append a new line use the normal editor_insert func.
** If position is not at the end, same function as the normal editor_insert.
*/

void	editor_insert_instant(t_editor *l, char c)
{
	if (l->pos && l->pos == l->len && (l->pos + l->plen) % l->cols == 0)
		editor_insert(l, c);
	if (l->len < l->buflen)
	{
		if (l->len == l->pos)
		{
			ft_putchar(c);
			l->buf[l->pos] = c;
			l->pos++;
			l->len++;
			l->buf[l->len] = '\0';
		}
		else
		{
			ft_memmove(l->buf + l->pos + 1, l->buf + l->pos, l->len - l->pos);
			l->buf[l->pos] = c;
			l->len++;
			l->pos++;
			l->buf[l->len] = '\0';
			refresh_line(l);
		}
	}
}
