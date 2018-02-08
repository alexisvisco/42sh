/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_process.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:17:46 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 13:21:26 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	shell_process(char *s)
{
	t_token	**tokens;
	t_block	*test;
	int		i;
	int		tablea[2];

	tokens = NULL;
	test = NULL;
	tablea[0] = 0;
	tablea[1] = 0;
	if (parse_tokens(&tokens, s) < 0)
		return (0);
	if (parse_block(tokens, &test) < 0)
		return (0);
	exec_or_and(tokens, test, tablea, 0);
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]->value);
		free(tokens[i]);
		i++;
	}
	free(tokens);
	free(test);
	return (0);
}
