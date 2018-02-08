/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_clear.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 12:22:56 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		b_clear(char **args, t_shell *shell)
{
	(void)args;
	(void)shell;
	write(STDOUT_FILENO, "\x1b[H\x1b[2J", 7);
	return (1);
}
