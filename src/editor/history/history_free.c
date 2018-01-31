/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_free.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 14:35:39 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 14:59:03 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	history_free(void)
{
	t_history *h;

	h = get_history();
	if (h)
	{
		heap_free(h->heap);
		free(h);
	}
}
