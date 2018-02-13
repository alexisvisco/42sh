/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_completions_env.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:44:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 15:27:22 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Retrieve all completions in the trie structure of env start with
** i->current_word
*/

void	get_completions_env(t_word_info *i, t_heap *h)
{
	trie_start_with(g_shell.env_trie, i->current_word, h);
}
