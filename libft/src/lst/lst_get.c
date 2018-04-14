/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_get.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 10:17:50 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_get(t_list **lst, int where)
{
	t_list	*tmp;
	int		i;

	if (!*lst)
		return (NULL);
	tmp = *lst;
	i = 0;
	while (tmp)
	{
		if (i == where)
			return (tmp);
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}
