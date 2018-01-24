/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_del_simple.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 15:58:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 22:10:27 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

void	ef_del_simple(t_editor *l)
{
	if (l->len > 0 && l->pos < l->len) {
		ft_memmove(l->buf + l->pos, l->buf + l->pos + 1, l->len - l->pos - 1);
		l->len--;
		l->buf[l->len] = '\0';
	}
}