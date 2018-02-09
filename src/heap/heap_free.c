/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 11:32:12 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 18:53:31 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	heap_free(t_heap *h)
{
	size_t i;

	i = 0;
	while (i < h->size)
	{
		if (h->list[i])
			h->free_func(h->list[i]);
		i++;
	}
	free(h->list);
	free(h);
	h = NULL;
}
