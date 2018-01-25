/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_growth.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 10:44:25 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 11:49:35 by aviscogl    ###    #+. /#+    ###.fr     */
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
		if (hp->list[i] == 0)
			hp->last_remove = i;
		tmp[i] = hp->list[i];
		i++;
	}
	free(hp->list);
	hp->size *= 2;
	hp->list = tmp;
}
