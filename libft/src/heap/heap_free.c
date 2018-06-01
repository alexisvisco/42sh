/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 11:32:12 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
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
	ft_memdel((void **)&(h->list));
	ft_memdel((void **)&h);
}
