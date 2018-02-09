/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_new.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/12 17:12:58 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/25 15:28:16 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_new(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	else
	{
		if (content != NULL)
		{
			new->content = (void *)ft_memalloc(
			sizeof(void) * (content_size + 1));
			if (new->content == NULL)
				return (NULL);
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		new->next = NULL;
	}
	return (new);
}
