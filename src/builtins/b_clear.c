/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_clear.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 18:51:05 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Clear the terminal
** Take no arguments
*/

int		b_clear(char **args, t_shell *shell)
{
	(void)args;
	(void)shell;
	write(STDOUT_FILENO, "\x1b[H\x1b[2J", 7);
	return (1);
}
