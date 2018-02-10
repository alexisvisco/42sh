/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_exec.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 16:59:52 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 13:54:37 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** index[0] = begin
** index[1] = end
*/

char		**extract_cmd(t_token **tokens, int *index)
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
** execute the next index
** num[0] = start index
** num[1] = num block
*/

int			exec_next_index(t_token **tokens, t_block *blocks, int *num,
	int ret)
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

static void	next_index(t_token **tokens, t_block *blocks, int *num, int *ind)
{
	ind[0] = num[0];
	ind[1] = go_to_next(tokens, blocks, num[1], num[0]);
	num[0] = ind[1] + 1;
}

static int	return_exec_value(char ***cmds, t_block *blocks, t_token **tokens)
{
	int ret;

	ret = exec_cmds(cmds, blocks, tokens);
	free_3d_tab(cmds);
	return (ret);
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

	if (blocks[num[1]].start_tok == -1)
		return (EXEC_FINISH);
	next_index(tokens, blocks, num, ind);
	argv = extract_cmd(tokens, ind);
	if ((ret == 1 && ft_strequ(argv[0], "&&"))
	|| (ret == 0 && ft_strequ(argv[0], "||")))
	{
		free_tab(argv);
		return (exec_next_index(tokens, blocks, num, ret));
	}
	if (analyze_next_and_or(argv[0]))
		delete_first_element(&argv);
	cmds = extract_all_pipes(argv);
	free_tab(argv);
	if ((g_shell.cmds = cmds) && replace_argv0_by_exec(cmds) == -1)
	{
		free_3d_tab(cmds);
		return (exec_next_index(tokens, blocks, num, 1));
	}
	ret = return_exec_value(cmds, blocks, tokens);
	return (exec_next_index(tokens, blocks, num, ret));
}
