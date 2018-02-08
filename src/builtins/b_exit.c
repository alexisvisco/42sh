/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_exit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:56:46 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/06 10:19:49 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		b_exit(char **args, t_shell *shell)
{
	int exit_status;

	(void)shell;
	disable_terminal(STDIN_FILENO);
	exit_shell();
	exit_status = (size_tab(args) >= 2) ? ft_atoi(args[1]) : 0;
	msg_builtins(SHELL_EXIT, exit_status);
	exit(exit_status);
}
