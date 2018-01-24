/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:48:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 22:26:51 by aviscogl    ###    #+. /#+    ###.fr     */
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
	e->buf[0] = 0;
	e->pos = 0;
	e->len = 0;
	j = 0;
	while (str[j])
	{
		editor_insert(e, str[j]);
		j++;
	}
	ef_go_end(e);
}

void	history_up(t_editor *e)
{
	t_history *hist;

	hist = get_history(e);
	if (hist->index == -1)
	{
		set_origin(e);
	}
	if (hist->heap->elements == 0 || hist->index == hist->heap->elements - 1)
		return ;
	hist->index++;
	heap_to_buf((size_t)hist->index, e);
}

void	history_down(t_editor *e)
{
	t_history *hist;

	hist = get_history(e);
	if (hist->index == -1)
		return ;
	else if (hist->index == 0)
	{
		hist->index = -1;
		origin_to_buf(e);
	}
	else if (hist->index > 0)
	{
		hist->index--;
		heap_to_buf((size_t)hist->index, e);
	}
}

void	history_add(t_editor *e)
{
	t_history *hist;

	hist = get_history(e);
	heap_add(hist->heap, ft_strdup(e->buf));
}

t_history	*get_history(t_editor *e)
{
	static t_history *hist = NULL;

	if (!hist)
	{
		hist = malloc(sizeof(t_history));
		hist->heap = heap_new(32);
		hist->index = -1;
		hist->origin[0] = '\0';
		set_origin(e);
	}
	return (hist);
}