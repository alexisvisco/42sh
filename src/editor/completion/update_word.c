/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   update_word.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 14:35:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 12:08:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Update the word at current position with the word passed in parameter
*/

void	update_word(t_editor *e, char *word)
{
	t_word_info info;

	info.end = e->pos;
	info.begin = e->pos;
	if (e->pos == 0 || e->buf[e->pos - 1] == ' ')
		editor_insert_str_without_refresh(e, word);
	else
	{
		get_word_at(e->buf, e->pos, &info);
		ef_move_cursor_to(e, info.end + 1);
		if (info.current_word)
		{
			ef_del_backspace_times(e,
			(unsigned int)ft_strlen(info.current_word));
			editor_insert_str_without_refresh(e, word);
			free(info.current_word);
		}
	}
	refresh_line(e);
}
