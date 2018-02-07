/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   msg_builtins.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 20:56:27 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/07 13:06:05 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <shell.h>


static char *g_msg_builtins[] = {
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
		"There is no history available at index %i from end.\n"
};

void   err_builtins(t_msg_builtins m, ...)
{
	va_list	ap;

	ft_printf("%s » ", SHELL_NAME);
	va_start(ap, m);
	core_pf(STDERR_FILENO, g_msg_builtins[m], ap);
	va_end(ap);
}

void   msg_builtins(t_msg_builtins m, ...)
{
	va_list	ap;

	ft_printf("%s » ", SHELL_NAME);
	va_start(ap, m);
	core_pf(STDOUT_FILENO, g_msg_builtins[m], ap);
	va_end(ap);
}
