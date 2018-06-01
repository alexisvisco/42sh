/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_growth.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 10:44:25 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	heap_growth(t_heap *hp)
{
	void			**tmp;
	size_t			i;

	i = 0;
	tmp = ft_memalloc(hp->size * 2);
	while (i < hp->size)
	{
		tmp[i] = hp->list[i];
		i++;
	}
	ft_memdel((void **)&(hp->list));
	hp->size *= 2;
	hp->list = tmp;
}
