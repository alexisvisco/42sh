/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bh_show_history.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:45:23 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:47:02 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Show the current history if there is no arguments
*/

int		show_history(t_shell *shell)
{
	t_heap *h;
	size_t i;
	size_t j;

	if (!shell->line_edit->history_data || !shell->line_edit->history_data->heap
		|| shell->line_edit->history_data->heap->elements == 0)
	{
		message_err(ERR_NO_HISTORY);
		return (0);
	}
	h = shell->line_edit->history_data->heap;
	i = 0;
	j = 0;
	while (i < h->elements)
	{
		if (h->list[i])
		{
			ft_printf(" * %i %s\n", j + 1, (char *)h->list[i]);
			j++;
		}
		i++;
	}
	return (1);
}
