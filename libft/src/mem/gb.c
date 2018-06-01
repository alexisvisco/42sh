/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gb.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/01 14:47:11 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/01 14:47:11 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>

static void *memalloc_bis(size_t s)
{
	void *str;

	str = malloc(sizeof(void *) * s);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, sizeof(void *) * s);
	return (str);
}

t_hashtable *get_mallocs()
{
	static t_hashtable *mallocs = NULL;

	if (!mallocs)
	{
		mallocs = memalloc_bis(sizeof(t_hashtable));
		mallocs->size = 512;
		mallocs->heaps = ft_memalloc(512);
		mallocs->free_func = free;
	}
	return mallocs;
}

void free_all()
{
	size_t i;
	size_t j;
	t_heap *h;

	i = 0;
	while (i < get_mallocs()->size)
	{
		h = get_mallocs()->heaps[i];
		if (h)
		{
			j = 0;
			while (j < h->size)
			{
				if (h->list[j])
					ht_default_free(get_mallocs(), h->list[j]);
				j++;
			}
			ft_memdel((void **) &(h->list));
			ft_memdel((void **) &h);
		}
		i++;
	}
	free((void **) &(get_mallocs()->heaps));
	free((void **) &get_mallocs);
}
