/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_clear.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/05 20:15:40 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int     b_clear(char **args, t_hashtable *envs)
{
	(void)args;
	(void)envs;
	write(STDOUT_FILENO, "\x1b[H\x1b[2J", 7);
	return (1);
}