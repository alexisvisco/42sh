/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_options.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 16:59:20 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 12:35:44 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <editor.h>

void	free_options(t_options *t)
{
	if (t->completion_data)
	{
		heap_free(t->completion_data->heap);
		free(t->completion_data);
	}
	if (t->history_data)
	{
		heap_free(t->history_data->heap);
		free(t->history_data);
	}
	free(t);
}
