/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   buf_append.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 15:56:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Append buffer with char *s of len len.
*/

void	buf_append(t_buf *ab, const char *s, int len)
{
	char	*new;
	int		i;
	int		j;

	new = ft_memalloc(ab->len + (size_t)len);
	i = -1;
	j = 0;
	while (ab->b && ab->b[++i])
		new[j++] = ab->b[i];
	i = -1;
	while (s && s[++i])
		new[j++] = s[i];
	new[j] = 0;
	ft_memdel((void**)&(ab->b));
	ab->b = new;
	ab->len += len;
}
