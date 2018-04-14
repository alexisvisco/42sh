/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_collect_if.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 09:32:43 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_collect_if(t_list *lst, void *data_ref, int (*cmp)())
{
	t_list	*new_list;

	if (!cmp || !lst || !data_ref)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		if (cmp(data_ref, lst->content))
			lst_push(&new_list, lst_new(lst->content, lst->content_size));
		lst = lst->next;
	}
	return (new_list);
}
