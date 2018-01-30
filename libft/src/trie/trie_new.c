/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trie_new.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 18:37:44 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 21:35:37 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# include "libft.h"

t_trie_node	*trie_new(void)
{
    t_trie_node	*root;
	int			i;

	root = malloc(sizeof(t_trie_node));
    root->is_word_end = 0;
    root->has_child = 0;

	i = 0;
	while (i < ALPHABET_SIZE)
	{
		root->children[i] = NULL;
		i++;
	}
    return (root);
}
