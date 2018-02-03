/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   completion.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:48:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 10:03:11 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	completion_next(t_editor *e)
{
	t_e_content *completion;

	completion = e->options->completion_data;
	if (completion->heap->elements == 0)
	{
		completion_delete(e);
		return ;
	}
	if (completion->index + 1 < (int64_t)completion->heap->elements)
	{
		completion->index++;
		update_word(e, (char *)completion->heap->list[completion->index]);
	}
	else
	{
		update_word(e, completion->origin);
		completion_delete(e);
	}
}

void	completion_handler(t_editor *e)
{
	init_completion(e);
	completion_next(e);
}

void	completion_delete(t_editor *e)
{
	t_e_content *completion;

	deb_printer("deletion of completion\n");
	completion = e->options->completion_data;
	e->mode = INSERTION;
	heap_free(completion->heap);
	free(e->options->completion_data);
	e->options->completion_data = NULL;
}

void	init_completion(t_editor *e)
{
	if (!e->options->completion_data)
	{
		e->mode = COMPLETION;
		e->options->completion_data = malloc(sizeof(t_e_content));
		e->options->completion_data->heap = heap_new(32);
		e->options->completion_data->index = -1;
		e->options->completion_data->origin[0] = '\0';
		get_completions(e);
	}
}
