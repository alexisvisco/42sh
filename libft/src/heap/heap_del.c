/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_del.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 11:27:30 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*heap_del(t_heap *heap, size_t n)
{
	void *tmp;

	if (n < heap->size)
	{
		tmp = heap->list[n];
		heap->list[n] = NULL;
		heap->elements--;
		heap_reorder(heap);
		return (tmp);
	}
	return (NULL);
}
