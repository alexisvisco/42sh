/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redistribute_pipe_redir.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 12:05:02 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 15:40:03 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int		count_pipes(char **argv)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (ft_strequ(argv[i], "|"))
			count++;
		i++;
	}
	return (count);
}

static int		end_of_cmd(char **argv)
{
	int	a;

	a = 0;
	while (argv[a])
		a++;
	return (a);
}

char			***extract_all_pipes(char **argv)
{
	char	***cmds;
	int		nb_cmds;
	int		i;
	int		j;
	int		k;

	nb_cmds = count_pipes(argv);
	cmds = malloc(sizeof(char**) * (nb_cmds + 2));
	cmds[nb_cmds + 1] = NULL;
	i = -1;
	while (++i <= nb_cmds)
		cmds[i] = malloc(sizeof(char*) * (end_of_cmd(argv) + 1));
	i = 0;
	j = 0;
	while (i <= nb_cmds)
	{
		k = 0;
		while (argv[j] && ft_strcmp(argv[j], "|"))
			cmds[i][k++] = ft_strdup(argv[j++]);
		cmds[i][k] = NULL;
		j++;
		i++;
	}
	return (cmds);
}
