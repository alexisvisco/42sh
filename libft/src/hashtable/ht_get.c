/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ht_get.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 14:41:21 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ht_get(t_hashtable *ht, const char *key)
{
	t_node *node;

	if (key)
	{
		node = ht_has(ht, key);
		return (node ? node->value : NULL);
	}
	return (NULL);
}
