/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor_insert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 21:30:31 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 10:52:35 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	editor_insert(t_editor *l, char c)
{
	if (l->len < l->buflen)
	{
		if (l->len == l->pos)
		{
			l->buf[l->pos] = c;
			l->pos++;
			l->len++;
			l->buf[l->len] = '\0';
			refresh_line(l);
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

void	editor_insert_without_refresh(t_editor *l, char c)
{
	if (l->len < l->buflen)
	{
		if (l->len == l->pos)
		{
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
		}
	}
}
