/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_binary_search.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 12:42:55 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

static int	levenshtein(char *s1, char *s2) {
	unsigned int s1len, s2len, x, y, lastdiag, olddiag;
	s1len = (unsigned int) ft_strlen(s1);
	s2len = (unsigned int) ft_strlen(s2);
	unsigned int column[s1len+1];
	for (y = 1; y <= s1len; y++)
		column[y] = y;
	for (x = 1; x <= s2len; x++) {
		column[0] = x;
		for (y = 1, lastdiag = x-1; y <= s1len; y++) {
			olddiag = column[y];
			column[y] = MIN3(column[y] + 1, column[y-1] + 1, lastdiag + (s1[y-1] == s2[x-1] ? 0 : 1));
			lastdiag = olddiag;
		}
	}
	return(column[s1len]);
}


void 		b_best_matchs(char *key, t_trie_node *tries)
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
		if (heap->list[i] && levenshtein(key, heap->list[i]) <= 2)
		{
			ft_printf(" * %s\n", heap->list[i]);
		}
		i++;
	}
}

int			b_binary_search(char **args, t_shell *shell)
{
	if (size_tab(args) < 1)
	{
		msg_builtins(ERR_BIN_SEARCH_FORMAT);
		return (0);
	}
	if (ht_get(shell->bin, args[0]))
		msg_builtins(MSG_SEARCH_BIN_FOUND, args[0]);
	else if (ft_strlen(args[0]) >= 2)
		b_best_matchs(args[0], shell->bin_trie);
	return (1);
}

