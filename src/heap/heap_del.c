/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_del.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 11:27:30 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 18:53:29 by ggranjon    ###    #+. /#+    ###.fr     */
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
		heap->last_remove = n;
		heap->elements--;
		return (tmp);
	}
	return (NULL);
}
