/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_remove_at.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 10:26:05 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
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
			ft_memdel((void **)&(node));
			return ;
		}
		prev = node;
		node = node->next;
		i++;
	}
}
