/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_process.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:17:46 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	shell_process(char *s)
{
	t_token	**tokens;
	t_block	*blocks;
	int		tablea[2];

	tokens = NULL;
	blocks = NULL;
	tablea[0] = 0;
	tablea[1] = 0;
	g_shell.line = s;
	if (parse_tokens(&tokens, s) < 0)
		return (0);
	if (parse_block(tokens, &blocks) < 0)
		return (0);
	exec_or_and(tokens, blocks, tablea, 0);
	free_toks(tokens);
	free(blocks);
	return (0);
}
