/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trie_delete.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 19:04:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:26 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	trie_delete(t_trie_node *r)
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
