/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_delete_curr_to_end.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:29:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 20:45:47 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	ef_delete_curr_to_end(t_editor *l)
{
	l->buf[l->pos] = '\0';
    l->len = l->pos;
	refresh_line(l);
}