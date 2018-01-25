/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_get_whole.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 10:47:45 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 11:49:09 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int64_t	heap_get_whole(t_heap *heap)
{
	size_t i;

	i = -1;
	while (++i < heap->size)
	{
		if (heap->list[i] == 0)
			return (i);
	}
	return (int64_t)-1;
}
