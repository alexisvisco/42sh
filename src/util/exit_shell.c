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
	rewrite_history_file(HISTORY_DATA);
	ht_free(g_shell.bin);
	ht_free(g_shell.env);
	trie_free(g_shell.bin_trie);
	trie_free(g_shell.env_trie);
	free_options(g_shell.line_edit);
	ft_memdel((void **)&(g_shell.line));
	free_options(g_shell.history_search);
	ht_free(get_builtins());
	ht_free(g_shell.vars);
	disable_terminal(0);
}
