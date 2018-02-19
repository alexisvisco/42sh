/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_search_msg.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/09 15:16:26 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 13:26:21 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		history_search_msg(void)
{
	ft_putstr("\n───────────────────────────────────────────────────────────\n"
	"Type something to search in the shell history.\n"
	"When results appear, type the index of the line you want.\n"
	"To quit type 'exit' in the prompt.\n"
	"───────────────────────────────────────────────────────────\n");
}
