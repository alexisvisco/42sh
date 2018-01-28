/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   messages.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 16:21:06 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/28 14:16:36 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	e_general(t_message m, char *arg)
{
	if (m == ERR_CMD_NOT_FOUND)
		ft_dprintf(2, "%s » Command not found: %s\n", SHELL_NAME, arg);
	if (m == ERR_NOTHING_ENTERED)
		ft_dprintf(2, "%s » You entered nothing...\n", SHELL_NAME);
	if (m == ERR_EXE_CMD)
		ft_dprintf(2, "%s » Error while executing command: %s\n", SHELL_NAME,
		arg);
	if (m == ERR_CTRL_C)
		ft_dprintf(2, "%s » Type 'exit' to quit this shell.\n", SHELL_NAME);
	if (m == SHELL_EXIT)
		ft_printf("%s » You killed me (exit code: %i)! Just say me why!\n",
		SHELL_NAME, *(int *)arg);
}

void	e_parse(t_eparse m, char *arg)
{
	if (m == ERR_REDIR)
		ft_dprintf(2, "%s » There is a redirection error\n", SHELL_NAME);
	if (m == ERR_QUOTE)
		ft_dprintf(2, "%s » Man... Seriously? Your quotes...\n", SHELL_NAME);
	if (m == ERR_PIPE)
		ft_dprintf(2, "%s » Review your pipes\n", SHELL_NAME);
	if (m == ERR_AFTER_FD)
		ft_dprintf(2, "%s » There is an error after your FD\n", SHELL_NAME);
	if (m == ERR_BAD_END)
		ft_dprintf(2, "%s » Your command must end by another thing\n", SHELL_NAME);
}
