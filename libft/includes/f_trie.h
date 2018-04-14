/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   f_trie.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 18:28:39 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _F_TRIE_H
# define _F_TRIE_H

# include "libft.h"

# define ALPHABET_SIZE 255

typedef struct			s_trie_node
{
	struct s_trie_node	*children[ALPHABET_SIZE];
	int					is_word_end;
	int					has_child;
}						t_trie_node;

t_trie_node				*trie_new(void);
void					trie_free(t_trie_node *root);
void					trie_insert(t_trie_node *root, const char *str);
int						trie_search(t_trie_node *root, const char *key);
int						trie_is_last_node(t_trie_node *root);
void					trie_start_with(t_trie_node *r, char *prefix,
t_heap *h);
int						trie_char_to_index(char c);

#endif
