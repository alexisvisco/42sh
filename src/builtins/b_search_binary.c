/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_search_binary.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 10:38:14 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		b_best_matchs(char *key, t_trie_node *tries)
{
	char	*first_letter;
	t_heap	*heap;
	size_t	i;

	first_letter = ft_char_to_str(key[0]);
	heap = heap_new(16);
	trie_start_with(tries, first_letter, heap);
	i = 0;
	while (i < heap->size)
	{
		if (heap->list[i] && ft_levenshtein(key, heap->list[i], ft_strlen(key),
		ft_strlen(heap->list[i])) <= 2)
			ft_printf(" * %s\n", heap->list[i]);
		i++;
	}
	free(first_letter);
	heap_free(heap);
}

int			b_search_binary(char **args, t_shell *shell)
{
	if (size_tab(args) < 2)
	{
		msg_builtins(ERR_BIN_SEARCH_FORMAT);
		return (0);
	}
	if (ht_get(shell->bin, args[1]))
		msg_builtins(MSG_SEARCH_BIN_FOUND, args[1]);
	else if (ft_strlen(args[1]) >= 2)
		b_best_matchs(args[1], shell->bin_trie);
	return (1);
}
