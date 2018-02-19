/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_foreach_i.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 13:17:55 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 13:26:21 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach_i(t_list *lst, void (*f)(t_list *elem, int))
{
	int i;

	i = 0;
	while (lst)
	{
		f(lst, i);
		lst = lst->next;
		i++;
	}
}
