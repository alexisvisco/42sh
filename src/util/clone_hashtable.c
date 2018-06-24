/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clone_hashtable.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/18 14:35:51 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/18 14:35:51 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>

t_hashtable	*clone_hashtable(t_hashtable *t)
{
	t_hashtable	*new;
	t_heap		*heap;
	size_t		i;
	size_t		j;

	new = ht_new(t->size);
	i = 0;
	while (i < t->size)
	{
		heap = t->heaps[i];
		j = 0;
		while (heap && heap->elements > 0 && j < heap->size)
		{
			if (heap->list[j])
				ht_set(new, ((t_node *)heap->list[j])->key,
				ft_strdup(((t_node *)heap->list[j])->value));
			j++;
		}
		i++;
	}
	return (new);
}
