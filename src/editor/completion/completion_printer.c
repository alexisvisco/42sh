/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   completion_printer.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 17:24:42 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 17:06:33 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <editor.h>

static size_t	get_max_length(t_heap *h)
{
	size_t i;
	size_t max;

	i = 0;
	max = 0;
	while (i < h->size)
	{
		if (h->list[i] && max < ft_strlen((char *)h->list[i]))
			max = ft_strlen((char *)h->list[i]);
		i++;
	}
	return (max);
}

/*
** Print all completions in columns above the prompt
*/

void			completion_printer(t_editor *e, t_heap *list)
{
	const size_t	max_len = get_max_length(list);
	int				max_colums;
	size_t			i;
	size_t			j;

	max_colums = ((int)e->cols / (int)max_len + 1) - 2;
	if (max_colums < 0)
		max_colums = 1;
	disable_terminal(STDIN_FILENO);
	ft_printf("\nListe des completions (%i):\n", list->elements);
	i = 0;
	j = 0;
	while (i < list->size)
	{
		if (list->list[i])
		{
			ft_printf("%*-s", max_len + 1, list->list[i]);
			j++;
		}
		if (((int)j == max_colums && !(j = 0)) || (i + 1 == list->size))
			ft_putchar('\n');
		i++;
	}
	enable_terminal(STDIN_FILENO);
}
