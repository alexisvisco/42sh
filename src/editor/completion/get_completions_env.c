/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_completions_env.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:44:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/01 10:53:46 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	get_completions_env(t_word_info *i, t_heap *h)
{
	trie_start_with(g_shell.env_trie, i->current_word, h);
}
