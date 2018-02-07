/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_echo.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 18:45:21 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int     b_echo(char **args, t_shell *shell)
{
	int without_nl;

	without_nl = 0;
	(void)shell;
	while (*(++args))
	{
		if (ft_strequ(*args, "-n"))
			without_nl = 1;
		else
		{
			ft_putstr(*args);
			if (*(args + 1) != NULL)
				ft_putchar(' ');
		}
	}
	if (!without_nl)
		ft_putchar('\n');
	return (1);
}