/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_set.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 13:27:45 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:18:35 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ht_set(t_hashtable *h, const char *key, void *val)
{
	t_node *node;

	node = ht_has_or_create(h, key);
	node->value = val;
}
