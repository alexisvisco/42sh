/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_move_cursor_to.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 13:53:33 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <editor.h>

/*
** Move the cursor to the needed position
*/

void	ef_move_cursor_to(t_editor *e, size_t position)
{
	while (e->pos != position)
		(e->pos < position) ? ef_move_right(e) : ef_move_left(e);
}
