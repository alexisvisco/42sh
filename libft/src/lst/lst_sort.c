/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_sort.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 11:33:52 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_sort(t_list **lst, int (*comparator)())
{
	int		changed;
	t_list	*current;

	if (!lst || !*lst || !comparator)
		return ;
	changed = 1;
	while (changed)
	{
		changed = 0;
		current = *lst;
		while (current->next)
		{
			if (comparator(current->content, current->next->content) > 0)
			{
				lst_swap(current, current->next);
				changed = 1;
			}
			current = current->next;
		}
	}
}
