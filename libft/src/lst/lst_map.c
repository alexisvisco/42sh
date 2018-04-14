/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_map.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 13:22:25 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_map(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*tmp;
	t_list	*first;

	if (!f || !lst)
		return (NULL);
	tmp = f(lst);
	if (!(new_list = lst_new(tmp->content, tmp->content_size)))
		return (NULL);
	first = new_list;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(new_list->next = lst_new(tmp->content, tmp->content_size)))
			return (NULL);
		new_list = new_list->next;
		lst = lst->next;
	}
	return (first);
}
