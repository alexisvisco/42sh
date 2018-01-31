/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_new.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 13:17:41 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 12:54:23 by aviscogl    ###    #+. /#+    ###.fr     */
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
