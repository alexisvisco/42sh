/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_move_word.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/04 09:09:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Move to the next word at RIGHT
*/

void	ef_move_word_right(t_editor *l)
{
	while (l->pos < l->len && l->buf[l->pos + 1] == ' ')
		l->pos++;
	while (l->pos < l->len && l->buf[l->pos + 1] != ' ')
		l->pos++;
}

/*
** Move to the next word at LEFT
*/

void	ef_move_word_left(t_editor *l)
{
	while (l->pos > 0 && l->buf[l->pos - 1] == ' ')
		l->pos--;
	while (l->pos > 0 && l->buf[l->pos - 1] != ' ')
		l->pos--;
}
