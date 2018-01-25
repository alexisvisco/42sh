/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   origin.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 21:08:58 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 10:53:16 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	set_origin(t_editor *e)
{
	t_history	*h;
	size_t	i;

	h = get_history(e);
	i = 0;
	while (e->buf[i])
	{
		h->origin[i] = e->buf[i];
		i++;
	}
	h->origin[i] = '\0';
}

void	origin_to_buf(t_editor *e)
{
	t_history	*h;
	size_t	i;

	h = get_history(e);
	ef_delete_entire_line(e);
	refresh_line(e);
	i = 0;
	while (h->origin[i])
	{
		editor_insert_without_refresh(e, h->origin[i]);
		i++;
	}
}