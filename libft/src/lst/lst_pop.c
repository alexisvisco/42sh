/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_pop.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 11:13:49 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:32:25 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_pop(t_list **lst)
{
	t_list *node;
	t_list *prev;

	if ((node = *lst) == NULL)
		return (NULL);
	prev = NULL;
	while (node)
	{
		if (node->next)
		{
			prev = node;
			node = node->next;
		}
		else
			break ;
	}
	prev->next = NULL;
	return (node);
}
