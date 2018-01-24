/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_del_backspace.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 15:23:51 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 22:10:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	ef_del_backspace(t_editor *l)
{
	if (l->pos > 0 && l->len > 0)
	{
		ft_memmove(l->buf + l->pos - 1, l->buf + l->pos, l->len - l->pos);
		l->pos--;
		l->len--;
		l->buf[l->len] = '\0';
	}
}