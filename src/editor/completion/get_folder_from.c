/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_folder_from.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 10:24:51 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Get only the folder from a path
** Sample:
**  src/shell/hey -> src/shell/
**  src/lex/trefv.c -> src/lex/
*/

char	*get_folder_from(char *str)
{
	const size_t	len = ft_strlen(str);
	size_t			i;
	size_t			prev;
	char			*n_str;

	i = 0;
	prev = 0;
	while (i < len)
	{
		if (str[i] == '/')
			prev = i;
		i++;
	}
	n_str = (char *)malloc(sizeof(char) * (prev + 2));
	n_str[prev + 1] = 0;
	ft_strncpy(n_str, str, prev + 1);
	return (n_str);
}
