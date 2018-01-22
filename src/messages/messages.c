/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   messages.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 16:21:06 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 16:54:54 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void	e_general(t_message m, char *arg)
{
	if (m == ERR_CMD_NOT_FOUND)
		ft_dprintf(2, "%s » Command not found: %s\n", SHELL_NAME, arg);
	if (m == ERR_QUOTE)
		ft_dprintf(2, "%s » Man... Seriously? Your quotes...\n", SHELL_NAME);
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
