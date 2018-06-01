/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_options.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 16:59:20 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <editor.h>

void	free_options(t_options *t)
{
	if (t->completion_data)
	{
		heap_free(t->completion_data->heap);
		ft_memdel((void **)&(t->completion_data));
	}
	if (t->history_data)
	{
		heap_free(t->history_data->heap);
		ft_memdel((void **)&(t->history_data));
	}
	ft_memdel((void **)&t);
}
