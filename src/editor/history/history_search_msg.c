/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   history_search_msg.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 13:26:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 13:28:50 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		history_search_msg(void)
{
	ft_putstr("\n-----------------------------------------------------------\n"
	"Type something to search in the shell history.\n"
	"When results appear, type the index of the line you want.\n"
	"To quit type search history prompt 'exit'.\n"
	"-----------------------------------------------------------\n");
}
