/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   core_exec_backquotes.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 15:47:42 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 20:18:23 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static void			next_index(t_token **tokens, t_block *blocks,
					int *num, int *ind)
{
	ind[0] = num[0];
	ind[1] = go_to_next(tokens, blocks, num[1], num[0]);
	num[0] = ind[1] + 1;
}

static t_backquotes	exec_next(t_token **tokens, t_block *blocks, int *num,
					t_backquotes *ret)
{
	if (blocks[num[1]].end_tok <= num[0])
	{
		num[1] += 1;
		num[0] = blocks[num[1]].start_tok;
		(*ret).status = 0;
		core_exec_backquotes(tokens, blocks, num, ret);
	}
	else
		core_exec_backquotes(tokens, blocks, num, ret);
	return (*ret);
}

static void			exec_and_join(t_backquotes *ret, char ***cmds)
{
	char	*tmp;
	char	*tmp2;

	tmp = (*ret).str;
	(*ret) = exec_backquotes(cmds);
	tmp2 = (*ret).str;
	(*ret).str = ft_mine_strjoin(tmp, (*ret).str);
	if (tmp)
		free(tmp);
	if (tmp2)
		free(tmp2);
	free_3d_tab(cmds);
}

/*
** num[0] = start index
** num[1] = num block
** ind is for the index of the beginnng and the end
*/

t_backquotes		core_exec_backquotes(t_token **tokens, t_block *blocks,
					int num[2], t_backquotes *ret)
{
	int		ind[2];
	char	**argv;
	char	***cmds;

	if (blocks[num[1]].start_tok == -1)
		return (*ret);
	next_index(tokens, blocks, num, ind);
	if (((*ret).status == 1 && ft_strequ(tokens[ind[0]]->value, "&&")) ||
		((*ret).status == 0 && ft_strequ(tokens[ind[0]]->value, "||")))
		return (exec_next(tokens, blocks, num, ret));
	argv = extract_cmd(tokens, ind);
	if (analyze_next_and_or(argv[0]))
		delete_first_element(&argv);
	cmds = extract_all_pipes(argv);
	free_tab(argv);
	if ((g_shell.cmds = cmds) && replace_argv0_by_exec(cmds) == -1)
	{
		free_3d_tab(cmds);
		(*ret).status = 1;
		return (exec_next(tokens, blocks, num, ret));
	}
	open_files(cmds);
	exec_and_join(ret, cmds);
	return (exec_next(tokens, blocks, num, ret));
}
