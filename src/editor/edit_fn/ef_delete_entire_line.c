/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_delete_entire_line.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:28:32 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/17 11:26:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Delete the entire line
*/

void	ef_delete_entire_line(t_editor *l)
{
	l->buf[0] = '\0';
	l->len = 0;
	l->pos = 0;
}
