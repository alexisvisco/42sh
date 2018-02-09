/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   messages.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 16:21:06 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 12:41:42 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static char	*g_msg_list[] = {
	"Command not found: %s\n",
	"You entered nothing...\n",
	"Error while executing command: %s\n",
	"TERM environment variable not set.\n",

	"There is a redirection error\n",
	"Man... Seriously? Your quotes...\n",
	"Review your pipes\n",
	"There is an error after your FD\n",
	"Your command must end by another thing\n",
	"Please stop comments, it's useless\n",
	"Syntax error near unexpected token %s\n",

	"%s is a directory!\n",
	"%s does not exist or permission denied!\n",
	"%s does not exist!\n",
	"%s permission denied!\n",

	"This shell is unsuported\n",
	"This operation is currently unsuported\n",

	"The command pwd did not work for an unknown reason.\n",
	"To set env use: setenv <key=value> [<key=value>...].\n",
	"Env variable %s set to %s.\n",
	"To unset env user: unsetenv <key> [<key>...].\n",
	"Env variable %s doesn't exist.\n",
	"Env variable %s was unset (the value was %s).\n",
	"You killed me (exit code: %i)! Just say me why ?\n",
	"To search binary use: search-binary <query>.\n",
	"One match found: %s.\n",
	"There is currently no history.\n",
	"Cannot get current working directory.\n",
	"Cannot access to the directory %s.\n",
	"No such directory.\n",
	"Current directory is now %s.\n",
	"There is no history available.\n",
	"There is no history available that contain %s.\n",
	"There is no history available that start with %s.\n",
	"There is no history available at index %i from begin.\n",
	"There is no history available at index %i from end.\n",
	"There is no previous working directory.\n"
};

/*
** Take the message number get with msg_list the number element and print it
** on stdout
*/

void		message(t_msgs m, ...)
{
	va_list	ap;

	ft_printf("%s » ", SHELL_NAME);
	va_start(ap, m);
	core_pf(STDOUT_FILENO, g_msg_list[m], ap);
	va_end(ap);
}

/*
** Take the message number get with msg_list the number element and print it
** on stderr
*/

void		message_err(t_msgs m, ...)
{
	va_list	ap;

	ft_printf("%s » ", SHELL_NAME);
	va_start(ap, m);
	core_pf(STDERR_FILENO, g_msg_list[m], ap);
	va_end(ap);
}

/*
** Take the message number get with msg_list the number element and print it
** on custom file descriptor
*/

void		message_fd(int fd, t_msgs m, ...)
{
	va_list	ap;

	ft_printf("%s » ", SHELL_NAME);
	va_start(ap, m);
	core_pf(fd, g_msg_list[m], ap);
	va_end(ap);
}
