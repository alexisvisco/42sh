/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_or_and.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 16:59:52 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 19:12:10 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** index[0] = begin
** index[1] = end
** il faut que je gère si j'ai une redir entre des || ou des &&
*/

char		**next_cmd(t_token **tokens, t_block *block, int num, int index[2])
{
	char	**ret;
	int		end;

	ret = NULL;
	ret = malloc(sizeof(char *) * (index[1] - index[0] + 1));
	ret[index[1] - index[0]] = NULL;
	while (index[0] < index[1])
	{
		argv[i] = ft_strdup(tokens[index[0]]->value);
		index[0]++;
	}
}

/*
** num[0] = start index 
** num[1] = num block
*/

int		go_next_index(t_token **tokens, t_block *blocks, int num[2])
{
	int		next_begin;
	
	next_begin = go_to_next(tokens, blocks, num[1], num[0]);
	if (block[num[1]].end_tok == next_begin)
	{
		num[1] += 1;
		num[0] = block[num[1]].start_tok;
		exec_or_and(tokens, blocks, num, 0);
	}
	else
	{
		num[0] = next_begin;
		exec_or_and(tokens, blocks, num);
	}
}

/*
** num[0] = start index 
** num[1] = num block
** I rlly fuck the 42 norm.
*/

int		exec_or_and(t_token **tokens, t_block *blocks, int num[2], int ret)
{
	int		tab[2];
	char	**argv;
	char	*node;

	node = NULL;
	if (is_executable(argv[0]))
		node = argv[0];
	else if ((node = ht_get(g_shell.bin, argv[0])))
		;
	else
	{
		e_general(ERR_CMD_NOT_FOUND, argv[0]);
		go_next_index(tokens, blocks, num, ret);
	}
	tab[0] = num[0];
	tab[1] = go_to_next(tokens, blocks, num[0] + 1, num[1]);
	argv = next_cmd(tokens, blocks, num[1], tab);
	if ((ret == 1 && analyze_next_and_or(tokens, num[0]) == 3)
		|| (ret == 0 && analyze_next_and_or(tokens, num[0]) == 4)
		go_next_index(tokens, blocks, num);
	else if (analyze_next_and_or(tokens, num[0]) == 0)
		ret = fork_result(char *node, char **argv)
	else
		ret = fork_result(char *node, argv + 1)
	go_next_index(tokens, blocks, num, ret);
}
