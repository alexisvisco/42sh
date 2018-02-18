/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_del.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 20:26:58 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/18 20:37:17 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "libft.h"

void	*heap_del(t_heap *heap, size_t n)
{
	void *tmp;

	if (n < heap->size && heap->list[n])
	{
		tmp = heap->list[n];
		heap->list[n] = NULL;
		heap->elements--;
		heap_reorder(heap);
		return (tmp);
	}
	return (NULL);
}
