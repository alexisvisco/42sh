/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_move_right.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:31:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 12:30:35 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Move current position of the cursor to the right if it is possible
*/

void	ef_move_right(t_editor *l)
{
	if (l->pos != l->len)
		l->pos++;
}
