/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_remove_at.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 10:26:05 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/02 16:57:42 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_remove_at(t_list **lst, int index, void (*del)(void *, size_t s))
{
	t_list	*node;
	t_list	*prev;
	int		i;

	if ((node = *lst) == NULL)
		return ;
	prev = NULL;
	i = 0;
	while (node)
	{
		if (i == index)
		{
			if (prev)
				prev->next = node->next;
			else
				*lst = node->next;
			del(node->content, node->content_size);
			free(node);
			return ;
		}
		prev = node;
		node = node->next;
		i++;
	}
}
