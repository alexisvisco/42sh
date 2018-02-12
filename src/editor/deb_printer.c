/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   deb_printer.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 18:44:10 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 09:27:52 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Printer that print when readline function is launched
** Print behind current line
*/

void	deb_printer(const char *format, ...)
{
	va_list	ap;
	int		write;

	disable_terminal(STDIN_FILENO);
	ft_putchar('\n');
	va_start(ap, format);
	write = core_pf(1, format, ap);
	va_end(ap);
	enable_terminal(STDIN_FILENO);
}
