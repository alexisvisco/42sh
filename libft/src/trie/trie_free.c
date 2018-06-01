/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trie_free.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 19:04:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
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
		trie_free(r->children[index]);
		index++;
	}
	ft_memdel((void **)&r);
}
