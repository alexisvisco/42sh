/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_clear.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 11:02:15 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_clear(t_list **lst)
{
	if (lst && *lst)
	{
		lst_clear(&(*lst)->next);
		ft_memdel((void **)&(*lst));
		*lst = NULL;
	}
}

void	lst_clear_free(t_list **lst)
{
	if (lst && *lst)
	{
		lst_clear(&(*lst)->next);
		if ((*lst)->content)
			ft_memdel(&((*lst)->content));
		ft_memdel((void **)&(*lst));
		*lst = NULL;
	}
}

void	lst_clear_fn(t_list **lst, void (*del)(void *, size_t s))
{
	if (lst && *lst)
	{
		lst_clear(&(*lst)->next);
		if (del)
			(*del)((*lst)->content, (*lst)->content_size);
		ft_memdel((void **)&(*lst));
		*lst = NULL;
	}
}
