/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   editor_insert.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 21:30:31 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 13:54:37 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Insert the character 'c' at cursor current position
** Then refresh the line
*/

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

/*
** Insert the character 'c' at cursor current position without
** refreshing the line
*/

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

/*
** Insert the string at cursor current position
*/

void	editor_insert_str(t_editor *l, char *str)
{
	while (*str)
	{
		editor_insert_without_refresh(l, *str);
		str++;
	}
	refresh_line(l);
}

/*
** Insert the string at cursor current position without
** refreshing the line
*/

void	editor_insert_str_without_refresh(t_editor *l, char *str)
{
	while (*str)
	{
		editor_insert_without_refresh(l, *str);
		str++;
	}
}
