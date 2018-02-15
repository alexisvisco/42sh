/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   word_is_command.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/14 18:30:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 12:08:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	word_is_command(t_word_info *i, t_word_info *prev)
{
	const char	*t[] = {"&&", "||", "&|", ";", "|", 0};

	if (i->current_word && (i->current_word[0] == '/' ||
	(i->current_word[0] == '.' && i->current_word[1] == '/')))
		return (0);
	if (i->begin == 0 || prev->current_word == NULL ||
	ft_strequ(prev->current_word, ""))
		return (1);
	if (ft_tab_contain(t, prev->current_word))
		return (1);
	return (0);
}
