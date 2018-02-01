/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_word_info.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:03:32 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 10:20:58 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

static char	*get_word_cursor(char *cmd, size_t cursor)
{
	const size_t	len = ft_strlen(cmd);
	size_t			i;
	size_t			j;

	i = cursor;
	if (cursor != 0)
	{
		while (--i && (i == 0 || cmd[i] != ' '))
			;
	}
	i = i == 0 ? 0 : i + 1;
	j = i;
	while (j != len && cmd[j] != ' ')
		j++;
	j = j == len ? (j) - i : j - i;
	if (j == 0)
		return (NULL);
	return (ft_strsub(cmd, i, j));
}

void	set_word_info(t_word_info *i, t_editor *e)
{
	i->current_word = get_word_cursor(e->buf, e->pos);
	i->prev_word = NULL;
	if (ft_strstarts_with(i->current_word, '$'))
		i->type = TYPE_ENV;
}