/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   central_exec.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 17:25:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 19:01:51 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void		exec_a_block(t_token **tokens, t_block *block, int num)
{
		int		begin;
		t_node	*node;
		char	**argv;
		pid_t	childpid;

		argv = extract_cmd_args(tokens, block, num);
		if ((node = ht_has(g_shell.bin, argv[0])))
		{
			execve(node->value, argv, NULL);
		}
		else
			e_general(ERR_CMD_NOT_FOUND, argv[0]);
}
/*
void		exec_all(t_token **tokens, t_block *blocks)
{
		int		i;

		i = 0;
		while (blocks[i].start_tok != -1)
		{		
			ft_printf(“%s\n”, (char *)node->value);
			i++;
		}
}
*/