/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_delete.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/02 16:47:57 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_delete(t_list **list, void (*del)(void *, size_t s))
{
	t_list	*current;
	t_list	*tmp;

	if (list)
	{
		current = *list;
		while (current)
		{
			if (del)
				(*del)(current->content, current->content_size);
			tmp = current;
			current = current->next;
			ft_memdel((void **)&tmp);
		}
	}
	*list = NULL;
}

void	lst_delete_free(t_list **list, void (*del)(void *, size_t s))
{
	t_list	*current;
	t_list	*tmp;

	if (list)
	{
		current = *list;
		while (current)
		{
			if (del)
				(*del)(current->content, current->content_size);
			if (current->content)
				ft_memdel(&(current->content));
			tmp = current;
			current = current->next;
			ft_memdel((void **)&tmp);
		}
	}
	*list = NULL;
}
