/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_word_info.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:03:32 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 10:46:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	get_word_at(char *cmd, size_t position, t_word_info *w)
{
	int64_t i;
	size_t	j;

	if ((cmd[position] == ' ' && position == 0) ||
		(cmd[position] == ' ' && cmd[position - 1] == ' '))
	{
		w->current_word = NULL;
		return ;
	}
	if (cmd[position] == ' ' || (position > (ft_strlen(cmd) - 1)))
		position--;
	i = (int64_t)position + 1;
	while (cmd[--i] != ' ' && i >= 0)
		;
	i = i < 0 ? 0 : i + 1;
	j = (size_t)i;
	while (cmd[++j] != ' ' && cmd[j])
		;
	j--;
	w->begin = (size_t)i;
	w->end = j;
	w->current_word = (ft_strsub(cmd, (unsigned int)i, j - (i - 1)));
}

/*
** Set all information about t_word_info, the word at cursor
** Define the end, the begin of the word and the type of the word
** Sample:
**  index 3 of 'hey im really happy' -> word = 'hey', start = 0, end = 2
**  index 9 of 'hey im really happy' -> word = 'really', start = 7, end = 11
** The types are set by this rule: if the word start with a '$' it's a env
** variable, else its a command or a path
*/

void	set_word_info(t_word_info *i, t_editor *e)
{
	get_word_at(e->buf, e->pos, i);
	if (!i->current_word)
	{
		i->current_word = ft_strdup("");
		i->type = TYPE_COMMAND_OR_PATH;
	}
	else if (ft_strstarts_with(i->current_word, '$'))
		i->type = TYPE_ENV;
	else
		i->type = TYPE_COMMAND_OR_PATH;
}
