/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_colum.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 15:48:09 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Set colum
*/

void	set_colum(t_editor *e, t_refresher *r, t_buf *b)
{
	char *tmp;

	r->col = (r->plen + (int)e->pos) % (int)e->cols;
	if (r->col)
		tmp = ft_sprintf("\r\x1b[%dC", r->col);
	else
		tmp = ft_strdup("\r");
	buf_append(b, tmp, (int)ft_strlen(tmp));
	e->oldpos = e->pos;
	free(tmp);
}
