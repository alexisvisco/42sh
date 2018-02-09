/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   completion_printer.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 17:24:42 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 15:12:14 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <editor.h>

void			completion_printer(t_editor *e, t_heap *list)
{
	size_t			i;
	size_t			j;

	disable_terminal(STDIN_FILENO);
	ft_printf("\nListe des completions (%i):\n", list->elements);
	i = 0;
	j = 0;
	(void)e;
	while (i < list->size)
	{
		if (list->list[i])
			ft_printf("%s\n", list->list[i]);
		i++;
	}
	enable_terminal(STDIN_FILENO);
}
