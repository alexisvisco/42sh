/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_clear.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 11:02:15 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 10:08:27 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_clear(t_list **lst)
{
	if (lst && *lst)
	{
		lst_clear(&(*lst)->next);
		free(*lst);
		*lst = NULL;
	}
}

void	lst_clear_free(t_list **lst)
{
	if (lst && *lst)
	{
		lst_clear(&(*lst)->next);
		if ((*lst)->content)
			free((*lst)->content);
		free(*lst);
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
		free(*lst);
		*lst = NULL;
	}
}
