/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   central_exec.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 17:25:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 13:32:18 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	fork_result(char *node, char **argv)
{
	int		status;
	pid_t	childpid;

	status = 0;
	childpid = fork();
	if (childpid == 0)
	{
		execve(node, argv, NULL);
	}
	else if (childpid > 0)
		wait(&status);
	else
		perror("Fork failed");	
	return (WEXITSTATUS(status));
}

void		exec_a_block(t_token **tokens, t_block *block, int num)
{
		char	*node;
		char	**argv;
		int		ret;

		argv = extract_cmd_args(tokens, block, num);
		if ((node = ht_get(g_shell.bin, argv[0])))
			ret = fork_result(node, argv);
		else
			e_general(ERR_CMD_NOT_FOUND, argv[0]);
		free_tab(argv);
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