/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_push.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 14:06:10 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 14:21:56 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_push(t_list **list, t_list *value)
{
	t_list *tmp;

	if (!*list)
	{
		*list = value;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = value;
}
