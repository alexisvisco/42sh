/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_new.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 10:31:49 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_heap	*heap_new(size_t default_size)
{
	t_heap *heap;

	heap = ft_memalloc(sizeof(t_heap));
	heap->size = default_size;
	heap->next_insert = 0;
	heap->elements = 0;
	heap->list = ft_memalloc(default_size);
	heap->free_func = free;
	return (heap);
}
