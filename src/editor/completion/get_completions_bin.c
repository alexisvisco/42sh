/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_completions_bin.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:41:23 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 12:08:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Retrieve all completions in the trie structure of binaries start with
** i->current_word
*/

void	get_completions_bin(t_word_info *i, t_heap *h)
{
	trie_start_with(g_shell.bin_trie, i->current_word, h);
}
