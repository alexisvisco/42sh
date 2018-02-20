/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_set.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 13:27:45 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:26 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ht_set(t_hashtable *h, const char *key, void *val)
{
	t_node *node;

	node = ht_has_or_create(h, key);
	if (node->value)
		h->free_func(node->value);
	node->value = val;
}
