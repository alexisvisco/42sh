/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_swap.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 11:38:32 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/29 10:13:45 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_swap(t_list *a, t_list *b)
{
	void	*c;
	size_t	tsi;

	c = a->content;
	tsi = a->content_size;
	a->content = b->content;
	a->content_size = b->content_size;
	b->content = c;
	b->content_size = tsi;
}
