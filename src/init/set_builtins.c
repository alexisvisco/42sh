/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_builtins.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 10:35:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 14:13:55 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Add builtins to completions
*/

void	set_builtins(void)
{
	size_t			i;
	size_t			j;
	t_heap			*h;
	t_hashtable		*ht;

	ht = get_builtins();
	i = 0;
	while (ht && i < ht->size)
	{
		h = ht->heaps[i];
		j = 0;
		while (h && j < h->size)
		{
			if (h->list[j])
				trie_insert(g_shell.bin_trie, ((t_node *)h->list[j])->key);
			j++;
		}
		i++;
	}
}
