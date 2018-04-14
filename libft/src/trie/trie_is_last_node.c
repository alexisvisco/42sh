/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trie_is_last_node.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 18:50:37 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		trie_is_last_node(t_trie_node *root)
{
	int i;

	i = 0;
	while (i < ALPHABET_SIZE)
	{
		if (root->children[i])
			return (0);
		i++;
	}
	return (1);
}
