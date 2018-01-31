/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 11:32:12 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 13:04:06 by aviscogl    ###    #+. /#+    ###.fr     */
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
		if (h->free_func)
			h->free_func(h->list[i]);
		i++;
	}
	free(h->list);
	free(h);
	h = NULL;
}
