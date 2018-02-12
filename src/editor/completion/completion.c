/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   completion.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:48:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 11:46:33 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Get the next completion, if the index of the completion reach the end of the
** list, the completion will be deleted and the current word will be the origin
** before the completion
*/

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
		completion->index = -1;
	}
}

/*
** This method is called when user type <TAB>
** Create a completion structure if not exist then call the completion_next
** method
*/

void	completion_handler(t_editor *e)
{
	init_completion(e);
	completion_next(e);
}

/*
** This method delete the structure t_e_content and
** reset options->completion_data to NULL
*/

void	completion_delete(t_editor *e)
{
	t_e_content *completion;

	completion = e->options->completion_data;
	if (completion)
	{
		e->mode = INSERTION;
		heap_free(completion->heap);
		free(e->options->completion_data);
		e->options->completion_data = NULL;
	}
}

/*
** This method init completion_data if not exist
** Init all types of completions with get_completions method
** Print all completions in columns above the prompt
*/

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
		if (e->options->completion_data->heap->elements >= 1)
			completion_printer(e, e->options->completion_data->heap);
	}
}
