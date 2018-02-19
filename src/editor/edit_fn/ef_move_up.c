/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_move_up.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:44:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 13:26:21 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Move current cursor position to up if possible
** If not possible go to the start position
*/

void	ef_move_up(t_editor *l)
{
	if (((int64_t)l->pos - (int64_t)l->cols) >= 0)
		l->pos -= l->cols;
	else
		l->pos = 0;
}
