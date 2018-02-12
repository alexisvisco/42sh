/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_move_word.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/04 09:09:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 20:47:23 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Move to the next word at right
*/

void	ef_move_word_right(t_editor *l)
{
	while (l->pos < l->len && l->buf[l->pos + 1] == ' ')
		l->pos++;
	while (l->pos < l->len && l->buf[l->pos + 1] != ' ')
		l->pos++;
}

/*
** Move to the next word at left
*/

void	ef_move_word_left(t_editor *l)
{
	while (l->pos > 0 && l->buf[l->pos - 1] == ' ')
		l->pos--;
	while (l->pos > 0 && l->buf[l->pos - 1] != ' ')
		l->pos--;
}
