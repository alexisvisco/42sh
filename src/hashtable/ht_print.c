/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 18:16:20 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 18:52:58 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ht_print(t_hashtable *t, void (*printer)(t_node *))
{
	t_heap	*heap;
	size_t	i;
	size_t	j;

	i = 0;
	ft_putstr("{\n");
	while (i < t->size)
	{
		heap = t->heaps[i];
		j = 0;
		while (heap && heap->elements > 0 && j < heap->size)
		{
			if (heap->list[j])
			{
				ft_putstr("  ");
				printer((t_node *)heap->list[j]);
				ft_putchar('\n');
			}
			j++;
		}
		i++;
	}
	ft_putstr("}\n");
}
