/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_e_content.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 14:35:39 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 18:42:35 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Free type of t_e_content used in autocompletion or in history
*/

void	free_e_content(t_e_content *h)
{
	if (h)
	{
		heap_free(h->heap);
		free(h);
	}
}
