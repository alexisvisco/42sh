/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   completion.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:48:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 18:50:26 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	completion_next(t_editor *e)
{
	t_e_content *completion;

	completion = e->options->completion_data;
	if (completion->heap->elements == 0)
		return ;
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
	// deb_printer("tcompletion_handler\n");
	init_completion(e);
	completion_next(e);
}

void	completion_delete(t_editor *e)
{
	t_e_content *completion;

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
		e->options->completion_data->index = 0;
		e->options->completion_data->origin[0] = '\0';
		get_completions(e);
		
	}
}
