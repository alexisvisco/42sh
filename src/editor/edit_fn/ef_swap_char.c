/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_swap_char.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:20:27 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 14:02:56 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	ef_swap_char(t_editor *l)
{
	int aux;

	if (l->pos > 0 && l->pos < l->len)
	{
		aux = l->buf[l->pos - 1];
		l->buf[l->pos - 1] = l->buf[l->pos];
		l->buf[l->pos] = aux;
		if (l->pos != l->len - 1)
			l->pos++;
		refresh_line(l);
	}
}
