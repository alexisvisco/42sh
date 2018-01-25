/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_remove.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 14:46:08 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:18:30 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_node	*ht_remove(t_hashtable *t, const char *key)
{
	const size_t	len = ht_hash(key);
	t_heap			*heap;
	t_node			*node;
	size_t			i;

	heap = t->heaps[len % t->size];
	if (heap == 0)
		return (NULL);
	i = 0;
	while (heap && heap->elements > 0 && i < heap->size)
	{
		node = (t_node *)heap->list[i];
		if (node && ft_strequ(node->key, key))
			return ((t_node *)heap_del(heap, i));
		i++;
	}
	return (NULL);
}
