/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   extract_cmd_and_args.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 18:06:54 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 18:42:25 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int			end_of_arg(t_token **tokens, t_block *block, int num)
{
	int	end;

	end = block[num].start_tok + 1;
	while (end <= block[num].end_tok)
	{
		if (tokens[end]->type != ARG)
			break ;
		end++;
	}
	return (end - block[num].start_tok - 1);
}

char		**extract_cmd_args(t_token **tokens, t_block *block, int num)
{
	char	**argv;
	int		i;
	int		end;

	end = end_of_arg(tokens, block, num);
	argv = malloc(sizeof(char *) * (end + 2));
	argv[end + 1] = NULL;
	i = 0;
	num = block[num].start_tok;
	while (i <= end)
	{
		printf("Num : %i\n", num);
		argv[i] = ft_strdup(tokens[num]->value);
		num++;
		i++;
	}
	return (argv);
}
