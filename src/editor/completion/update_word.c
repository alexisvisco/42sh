/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   update_word.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 14:35:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 18:27:55 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	update_word(t_editor *e, char *word)
{
	char *wordx;

	if (e->pos == 0 || e->buf[e->pos - 1] == ' ')
		editor_insert_str_without_refresh(e, word);
	else
	{
		wordx = get_word_cursor(e->buf, e->pos);
		ef_del_backspace_times(e, ft_strlen(wordx));
		editor_insert_str_without_refresh(e, word);
		free(wordx);
	}
	refresh_line(e);
}