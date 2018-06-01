/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_reorder.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/16 21:10:12 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 10:15:28 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	heap_reorder(t_heap *h)
{
	void	**tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tmp = ft_memalloc(h->size);
	while (j < h->size)
	{
		if (h->list[j])
		{
			tmp[i] = h->list[j];
			i++;
		}
		j++;
	}
	h->next_insert = i;
	ft_memdel((void **)&(h->list));
	h->list = tmp;
}
