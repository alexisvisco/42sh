/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_tab.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 10:38:35 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 21:14:50 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Free an array of strings
*/

void	free_tab(char **table)
{
	int i;

	i = -1;
	if (table)
	{
		while (table[++i])
			free(table[i]);
		free(table);
	}
}
