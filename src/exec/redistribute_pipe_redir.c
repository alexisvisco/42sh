/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   redistribute_pipe_redir.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/02 12:05:02 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/02 19:13:03 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			there_is_pipe(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '|')
			return (i);
		i++;
	}
	return (0);
}

int			there_is_redir(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '>' || argv[i][0] == '<')
			return (i);
		i++;
	}
	return (0);
}

static int		end_of_cmd(t_token **tokens, t_block *block, int num)
{
	int	end;

	end = block[num].start_tok + 1;
	while (end <= block[num].end_tok)
	{
		if (ft_strequ(tokens[end]->value, "|"))
			break ;
		end++;
	}
	return (end - block[num].start_tok - 1);
}

char			**extract_cmd_pipes(t_token **tokens, t_block *block, int num)
{
	char	**argv;
	int		i;
	int		end;

	end = end_of_cmd(tokens, block, num);
	argv = malloc(sizeof(char *) * (end + 2));
	argv[end + 1] = NULL;
	i = 0;
	num = block[num].start_tok;
	while (i <= end)
	{
		argv[i] = ft_strdup(tokens[num]->value);
		num++;
		i++;
	}
	return (argv);
}
