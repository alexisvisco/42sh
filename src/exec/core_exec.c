/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_exec.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 16:59:52 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 19:10:38 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** index[0] = begin
** index[1] = end
** il faut que je gère si j'ai une redir entre des || ou des &&
** Next_cmd is ok
*/

char		**next_cmd(t_token **tokens, int index[2])
{
	char	**ret;
	int		i;

	ret = NULL;
	i = 0;
	ret = malloc(sizeof(char *) * (index[1] - index[0] + 2));
	ret[index[1] - index[0] + 1] = NULL;
	while (index[0] <= index[1])
	{
		ret[i] = ft_strdup(tokens[index[0]]->value);
		index[0]++;
		i++;
	}
	return (ret);
}

/*
** num[0] = start index 
** num[1] = num block
*/

int			go_next_index(t_token **tokens, t_block *blocks, int num[2], int ret)
{
	if (blocks[num[1]].end_tok <= num[0])
	{
		num[1] += 1;
		num[0] = blocks[num[1]].start_tok;
		exec_or_and(tokens, blocks, num, 0);
	}
	else
		exec_or_and(tokens, blocks, num, ret);
	return (1);
}

/*
** num[0] = start index 
** num[1] = num block
** I rlly fuck the 42 norm.
** ind is for the index of the beginnng and the end
*/

int			exec_or_and(t_token **tokens, t_block *blocks, int num[2], int ret)
{
	int		ind[2];
	char	**argv;
	char	***cmds;
	char	*node;
	int		output_file;

	node = NULL;
	if (blocks[num[1]].start_tok == -1)
		return (EXEC_FINISH);

	ind[0] = num[0];
	ind[1] = go_to_next(tokens, blocks, num[1], num[0]);

	argv = next_cmd(tokens, ind);

	num[0] = ind[1] + 1;
	if ((ret == 1 && ft_strequ(argv[0], "&&"))
	|| (ret == 0 && ft_strequ(argv[0], "||")))
	{
		free_tab(argv);
		return (go_next_index(tokens, blocks, num, ret));
	}
	else if (analyze_next_and_or(argv[0]))
		delete_first_element(&argv);

	cmds = extract_all_pipes(argv);
	free_tab(argv);
	if (replace_argv0_by_exec(cmds) == -1)
	{
		free_3d_tab(cmds);
		return (go_next_index(tokens, blocks, num, 1));
	}
	if ((output_file = call_right_redir(cmds)) == -1)
		return (go_next_index(tokens, blocks, num, 1));
//	ret = fork_result(node, argv);
	ret = exec_all_pipe(cmds, output_file);
	free_3d_tab(cmds);
	return (go_next_index(tokens, blocks, num, ret));
}
