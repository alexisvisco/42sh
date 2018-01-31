/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exit_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 13:47:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 20:43:32 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	exit_shell(void)
{
	ht_free(g_shell.bin);
	ht_free(g_shell.env);
	if (g_shell.line_edit->history_data)
		free_e_content(g_shell.line_edit->history_data);
	if (g_shell.line_edit->completion_data)
		free_e_content(g_shell.line_edit->history_data);
	trie_free(g_shell.bin_trie);
}
