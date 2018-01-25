/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:48:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 14:02:18 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

static void	heap_to_buf(size_t i, t_editor *e)
{
	t_history	*hist;
	char		*str;
	size_t		j;

	hist = get_history(e);
	str = (char *)heap_get(hist->heap, i);
	ef_delete_entire_line(e);
	refresh_line(e);
	j = 0;
	while (str[j])
	{
		editor_insert_without_refresh(e, str[j]);
		j++;
	}
}

/*
** Get the old history compared to what you've been typing lately
*/

void		history_up(t_editor *e)
{
	t_history *hist;

	hist = get_history(e);
	if (hist->heap->elements == 0)
		return ;
	if (hist->index == -1)
	{
		hist->index = hist->heap->next_insert;
		set_origin(e);
	}
	if (hist->index - 1 < 0)
		return ;
	hist->index--;
	heap_to_buf((size_t)hist->index, e);
}

/*
** Get the history closest to what you've been typing
** If you exceed the heap, replace the line with the origin
** your line before using history
*/

void		history_down(t_editor *e)
{
	t_history *hist;

	hist = get_history(e);
	if (hist->index == -1)
		return ;
	else if (hist->index + 1 == (int64_t)hist->heap->next_insert)
	{
		hist->index = -1;
		origin_to_buf(e);
	}
	else if (hist->index + 1 < (int64_t)hist->heap->next_insert)
	{
		hist->index++;
		heap_to_buf((size_t)hist->index, e);
	}
}

/*
** Add the current line to the history
** Heap dynamicly increase the size
*/

void		history_add(t_editor *e)
{
	t_history *hist;

	hist = get_history(e);
	heap_add(hist->heap, ft_strdup(e->buf));
}

/*
** Getting the history structure
** If it is not present, create it
*/

t_history	*get_history(t_editor *e)
{
	static t_history *hist = NULL;

	(void)e;
	if (!hist)
	{
		hist = malloc(sizeof(t_history));
		hist->heap = heap_new(32);
		hist->index = -1;
		hist->origin[0] = '\0';
	}
	return (hist);
}
