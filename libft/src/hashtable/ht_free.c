/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_free.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 15:09:30 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ht_default_free(t_hashtable *t, void *a)
{
	t_node *n;

	(void)t;
	if (a)
	{
		n = (t_node *)a;
		ft_memdel((void **)&(n->key));
		if (n->value && t->free_func)
			t->free_func(n->value);
		ft_memdel(&a);
	}
}

void	ht_free(t_hashtable *t)
{
	size_t i;
	size_t j;
	t_heap *h;

	i = 0;
	while (i < t->size)
	{
		h = t->heaps[i];
		if (h)
		{
			j = 0;
			while (j < h->size)
			{
				if (h->list[j])
					ht_default_free(t, h->list[j]);
				j++;
			}
			ft_memdel((void **)&(h->list));
			ft_memdel((void **)&h);
		}
		i++;
	}
	ft_memdel((void **)&(t->heaps));
	ft_memdel((void **)&t);
}
