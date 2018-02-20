/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bh_clear_history.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:46:43 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:47:10 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Clear entierly the history
*/

int		clear_history(void)
{
	heap_free(HISTORY_DATA);
	HISTORY_DATA = heap_new(16);
	message(MSG_HISTORY_CLEARED);
	return (1);
}
