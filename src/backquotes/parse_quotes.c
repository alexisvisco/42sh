/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_quotes.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/07 12:18:54 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 12:18:54 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int	backq_quotes(char **str)
{
	char	*tmp;

	tmp = ft_strdup(*str);
	if (count_tokens(tmp) == -2)
	{
		ft_memdel((void **)str);
		ft_memdel((void **)&tmp);
		message_err(ERR_BACKQUOTES);
		return (-1);
	}
	ft_memdel((void **)&tmp);
	return (0);
}
