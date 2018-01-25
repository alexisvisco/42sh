/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_new.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 10:31:49 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 14:35:51 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_heap	*heap_new(size_t default_size)
{
	t_heap *heap;

	heap = malloc(sizeof(t_heap));
	heap->size = default_size;
	heap->next_insert = 0;
	heap->elements = 0;
	heap->last_remove = -1;
	heap->list = ft_memalloc(default_size);
	return (heap);
}
