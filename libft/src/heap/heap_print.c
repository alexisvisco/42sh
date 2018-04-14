/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   heap_print.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 19:50:39 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
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
