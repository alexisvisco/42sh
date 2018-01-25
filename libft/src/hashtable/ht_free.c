/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 15:09:30 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:37:15 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ht_default_free(void *a)
{
	t_node *n;

	if (a)
	{
		n = (t_node *)a;
		free(n->key);
		if (n->value)
			free(n->value);
		free(a);
	}
}

void	ht_free(t_hashtable *t, void (*del)(void *))
{
	size_t i;
	t_heap *h;

	i = 0;
	while (i < t->size)
	{
		h = t->heaps[i];
		if (h)
			heap_free(h, del);
		i++;
	}
	free(t->heaps);
	free(t);
}
