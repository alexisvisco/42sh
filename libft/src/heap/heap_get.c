/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_get.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 10:51:59 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 11:57:17 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*heap_get(t_heap *heap, size_t n)
{
	if (n < heap->size)
		return (heap->list[n]);
	return (NULL);
}
