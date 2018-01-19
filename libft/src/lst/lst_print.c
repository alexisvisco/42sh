/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lst_print.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 13:59:12 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/26 11:10:13 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	lst_print(t_list *list, void (*print_function)(t_list*))
{
	if (!list)
		return ;
	ft_putchar('{');
	while (list)
	{
		print_function(list);
		list = list->next;
		if (list)
			ft_putstr(", ");
	}
	ft_putstr("}\n");
}
