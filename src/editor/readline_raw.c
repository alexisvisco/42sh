/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readline_raw.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 10:16:16 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 10:34:54 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

int		readline_raw(char *buf, size_t buflen, const char *prompt)
{
	int count;

	if (buflen == 0 || enable_terminal(STDIN_FILENO) == -1)
        return -1;
	count = editor(STDIN_FILENO, STDOUT_FILENO, buf, buflen, prompt);
	disable_terminal(STDIN_FILENO);
	ft_putchar_fd(STDOUT_FILENO, "\n");
	return (count);
}