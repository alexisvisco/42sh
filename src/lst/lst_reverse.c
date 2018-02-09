/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_reverse.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 11:32:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 11:42:56 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_reverse(t_list **list)
{
	t_list	*prev;
	t_list	*node;
	t_list	*next;

	if (!list || (node = *list) == NULL)
		return ;
	prev = NULL;
	while (node)
	{
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
	*list = prev;
}
