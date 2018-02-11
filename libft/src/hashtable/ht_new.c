/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_new.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 13:17:41 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/11 17:29:50 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_hashtable	*ht_new(size_t size)
{
	t_hashtable *hasht;

	hasht = malloc(sizeof(t_hashtable));
	hasht->size = size;
	hasht->heaps = ft_memalloc(size);
	hasht->free_func = free;
	return (hasht);
}
