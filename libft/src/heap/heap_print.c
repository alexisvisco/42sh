/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_print.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 10:57:55 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:19:17 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	heap_print(t_heap *h, void (*print_function)(void*))
{
	size_t i;

	i = 0;
	ft_putstr("[");
	while (i < h->size)
	{
		if (h->list[i] == 0)
			ft_putstr("NULL");
		else
			print_function(h->list[i]);
		if (i < h->size - 1)
			ft_putstr(", ");
		i++;
	}
	ft_putstr("]\n");
}
