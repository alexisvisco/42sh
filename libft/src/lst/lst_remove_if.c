/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_remove_if.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 10:55:31 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_remove_if(t_list **lst, void *data_ref, int (*cmp)())
{
	t_list *node;
	t_list *prev;

	if ((node = *lst) == NULL)
		return ;
	prev = NULL;
	while (node)
	{
		if ((*cmp)(node->content, data_ref) == 1)
		{
			if (prev)
				prev->next = node->next;
			else
				*lst = node->next;
		}
		prev = node;
		node = node->next;
	}
}
