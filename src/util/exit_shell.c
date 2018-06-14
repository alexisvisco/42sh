/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 13:47:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
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
	if (g_shell.line_edit)
		rewrite_history_file(HISTORY_DATA);
	if (g_shell.bin)
		ht_free(g_shell.bin);
	if (g_shell.bin)
		ht_free(g_shell.env);
	if (g_shell.bin_trie)
		trie_free(g_shell.bin_trie);
	if (g_shell.env_trie)
		trie_free(g_shell.env_trie);
	if (g_shell.vars_trie)
		trie_free(g_shell.vars_trie);
	if (g_shell.line_edit)
		free_options(g_shell.line_edit);
	ft_memdel((void **)&(g_shell.line));
	if (g_shell.history_search)
		free_options(g_shell.history_search);
	if (g_shell.vars)
		ht_free(g_shell.vars);
	if (get_builtins())
		ht_free(get_builtins());
	disable_terminal(0);
}
