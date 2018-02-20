/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_delete_curr_to_end.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:29:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** If possible delete only from the current position to the end
*/

void	ef_delete_curr_to_end(t_editor *l)
{
	l->buf[l->pos] = '\0';
	l->len = l->pos;
}
