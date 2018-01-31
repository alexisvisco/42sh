/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trie_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 19:04:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 14:16:45 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	trie_free(t_trie_node *r)
{
	int		index;

	index = 0;
	while (index < ALPHABET_SIZE)
	{
		if (!r->children[index])
		{
			index++;
			continue ;
		}
		trie_delete(r->children[index]);
		index++;
	}
	free(r);
}
