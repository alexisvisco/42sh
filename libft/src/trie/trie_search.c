/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trie_search.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 18:47:27 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 14:10:08 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		trie_search(t_trie_node *root, const char *key)
{
	const size_t	length = ft_strlen(key);
	t_trie_node		*trie_node;
	size_t			level;
	int				index;

	trie_node = root;
	level = 0;
	while (level < length)
	{
		index = trie_char_to_index(key[level]);
		if (!trie_node->children[index])
			return (0);
		trie_node = trie_node->children[index];
		level++;
	}
	return (trie_node != NULL && trie_node->is_word_end);
}
