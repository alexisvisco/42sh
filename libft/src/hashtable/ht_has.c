/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_has.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 13:30:10 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:18:10 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_node			*ht_has(t_hashtable *t, const char *key)
{
	const size_t	len = ht_hash(key);
	t_heap			*heap;
	t_node			*node;
	size_t			i;

	heap = t->heaps[len % t->size];
	if (heap == 0)
	{
		t->heaps[len % t->size] = heap_new(8);
		heap = t->heaps[len % t->size];
	}
	i = 0;
	while (heap && heap->elements > 0 && i < heap->size)
	{
		node = (t_node *)heap->list[i];
		if (node && ft_strequ(node->key, key))
			return (node);
		i++;
	}
	return (NULL);
}

t_node			*ht_has_or_create(t_hashtable *t, const char *key)
{
	const size_t	len = ht_hash(key);
	t_heap			*heap;
	t_node			*node;
	size_t			i;

	heap = t->heaps[len % t->size];
	if (heap == 0)
	{
		t->heaps[len % t->size] = heap_new(8);
		heap = t->heaps[len % t->size];
	}
	i = 0;
	while (heap && heap->elements > 0 && i < heap->size)
	{
		node = (t_node *)heap->list[i];
		if (node && ft_strequ(node->key, key))
			return (node);
		i++;
	}
	node = malloc(sizeof(t_node));
	node->key = ft_strdup(key);
	heap_add(heap, node);
	return (node);
}
