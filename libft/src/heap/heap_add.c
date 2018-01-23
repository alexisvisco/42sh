/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_add.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 10:36:37 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:18:49 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	simple_add(t_heap *heap, void *content)
{
	if (heap->last_remove != -1)
	{
		heap->list[heap->last_remove] = content;
		heap->last_remove = -1;
		return (1);
	}
	else if (heap->next_insert < heap->size)
	{
		heap->list[heap->next_insert] = content;
		heap->next_insert++;
		return (1);
	}
	return (0);
}

void		heap_add(t_heap *heap, void *content)
{
	int64_t whole;

	if (simple_add(heap, content))
		heap->elements++;
	else
	{
		if ((whole = heap_get_whole(heap)) != -1)
		{
			heap->list[whole] = content;
			heap->elements++;
		}
		else
		{
			heap_growth(heap);
			heap_add(heap, content);
		}
	}
}
