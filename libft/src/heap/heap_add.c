/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_add.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 10:36:37 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	simple_add(t_heap *heap, void *content)
{
	if (heap->next_insert < heap->size)
	{
		heap->list[heap->next_insert] = content;
		heap->next_insert++;
		return (1);
	}
	return (0);
}

void		heap_add(t_heap *heap, void *content)
{
	if (simple_add(heap, content))
		heap->elements++;
	else
	{
		heap_growth(heap);
		heap_add(heap, content);
	}
}
