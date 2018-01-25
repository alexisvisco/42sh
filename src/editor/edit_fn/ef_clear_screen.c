/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ef_clear_screen.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/23 20:31:56 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 10:48:16 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** Clear the screen
*/

void	ef_clear_screen(t_editor *l)
{
	write(STDOUT_FILENO, "\x1b[H\x1b[2J", 7);
}
