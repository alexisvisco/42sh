/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   backquotes_parsing.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 14:28:33 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 18:59:44 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	parsing(t_token **tokens, int i)
{
	t_token	**u_tokens;
	t_block	*u_blocks;

	u_tokens = NULL;
	u_blocks = NULL;
	if (tokens[i]->value[ft_strlen(tokens[i]->value) - 1] == '`')
		tokens[i]->value[ft_strlen(tokens[i]->value) - 1] = '\0';
	else
		return (-1);
	if (parse_tokens(&u_tokens, (tokens[i]->value + 1)) < 0)
		return (-2);
	else if (parse_block(tokens, &u_blocks) < 0)
		return (-3);

	/***/
	int j = 0;
	while (u_tokens[j])
	{
		ft_printf("u_tokens %-2i : %-15s  valeur =  %i \n", j, u_tokens[j]->value, u_tokens[j]->type);
		j++;
	}
	ft_printf("\n");
	/****/

	return (0);
}

int 		seek_backquotes(t_token **tokens)
{
	int		i;

	i = 0;
	while (tokens[i])
	{
		if (tokens[i]->value && tokens[i]->value[0] == '`')
			if (parsing(tokens, i) < 0)
				return (-1);
		i++;
	}
	return (0);
}

