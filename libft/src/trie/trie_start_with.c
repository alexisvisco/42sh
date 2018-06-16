/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trie_start_with.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 18:52:07 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*set_next_prefix(char *tmp, int i)
{
	char	*tmpx;
	char	*tmp_ch;

	tmp_ch = ft_memalloc(sizeof(char) * 2);
	tmp_ch[0] = (char)i;
	tmp_ch[1] = 0;
	tmpx = ft_strjoin(tmp, tmp_ch);
	ft_memdel((void **)&tmp_ch);
	return (tmpx);
}

static void	trie_start_with_a(t_trie_node *root, char *prefix, t_heap *heap)
{
	char	*tmp;
	char	*tmpx;
	int		i;

	tmp = ft_strdup(prefix);
	if (root->is_word_end)
		heap_add(heap, ft_strdup(prefix));
	if (trie_is_last_node(root))
	{
		ft_memdel((void **)&tmp);
		return ;
	}
	i = -1;
	while (++i < ALPHABET_SIZE)
	{
		if (root->children[i])
		{
			tmpx = set_next_prefix(tmp, i);
			trie_start_with_a(root->children[i], tmpx, heap);
			ft_memdel((void **)&tmpx);
		}
	}
	ft_memdel((void **)&tmp);
}

void		trie_start_with(t_trie_node *root, char *prefix, t_heap *heap)
{
	t_trie_node *cr;
	size_t		level;
	size_t		length;
	int			index;

	if (!prefix || !root || !heap)
		return ;
	length = ft_strlen(prefix);
	level = 0;
	cr = root;
	while (level < length)
	{
		index = trie_char_to_index(prefix[level]);
		if (!cr->children[index])
			return ;
		cr = cr->children[index];
		level++;
	}
	if (cr->is_word_end && !cr->has_child)
	{
		heap_add(heap, ft_strdup(prefix));
		return ;
	}
	if (!trie_is_last_node(cr))
		trie_start_with_a(cr, prefix, heap);
}
