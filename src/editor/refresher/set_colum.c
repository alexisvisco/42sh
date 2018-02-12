/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_colum.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 15:48:09 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 12:35:44 by aviscogl    ###    #+. /#+    ###.fr     */
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
