/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 13:47:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 17:06:33 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** At exit, free all variables to avoid leaks
** Yes leaks are a pain.
*/

void	exit_shell(void)
{
	ht_free(g_shell.bin);
	ht_free(g_shell.env);
	trie_free(g_shell.bin_trie);
	trie_free(g_shell.env_trie);
	free_options(g_shell.line_edit);
	free(g_shell.line);
	free_options(g_shell.history_search);
	ht_free(get_builtins());
	disable_terminal(0);
}
