/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bh_history_help.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:58:10 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 09:58:54 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Show history help
*/

int	history_help(void)
{
	ft_printf("\n* history [n]\n* history -c\n* history -d offset\n* "
					"history [-anrw] [filename]\n* history -e arg\n\n");
	ft_printf("Explanation of each arguments: \n");
	ft_printf(" -c: Clear the history list. This may be combined "
"with the other options to replace the history list completely.\n");
	ft_printf(" -d: offset: Delete the history entry at position "
"offset. offset should be specified as it appears when the history is"
					"displayed.\n");
	ft_printf(" -a: Append the new history lines to the history f"
					"ile.\n");
	ft_printf(" -n: Append the history lines not already read fro"
					"m the history file to the current history list.\n");
	ft_printf(" -r: Write out the current history list to the his"
					"tory file.\n");
	ft_printf(" -e: Perform a command without storing the results"
					" in the history list.\n");
	return (1);
}
