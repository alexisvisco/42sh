/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bh_del_history_at.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:47:29 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:50:57 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Delete at position x the element in the history
*/

int		del_history_at(char **args)
{
	char	*arg;
	char	*prev;
	int		offset;

	arg = get_first_arg(args);
	if (arg == NULL)
	{
		message_err(ERR_HISTORY_OFFSET_NEEDED);
		return (0);
	}
	offset = ft_atoi(arg);
	if (offset < 0 || offset >= (int)HISTORY_DATA->elements)
	{
		message_err(ERR_HISTORY_OFFSET_INVALID, offset);
		return (0);
	}
	prev = heap_del(HISTORY_DATA, (size_t)offset);
	message(MSG_HISTORY_DELETED, offset, prev);
	free(prev);
	return (1);
}
