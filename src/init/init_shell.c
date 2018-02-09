/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 18:49:36 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 15:02:11 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

/*
** Display a fun and cool message when shell start !
*/

static void		print_welcome_message(void)
{
	ft_printf("\n╭───────────────────────────────────────────────────────╮\n");
	ft_printf("│                                                       │\n");
	ft_printf("│                                                       │\n");
	ft_printf("│          Welcome to Alexis and Guillaume's            │\n");
	ft_printf("│                        shell                          │\n");
	ft_printf("│                                                       │\n");
	ft_printf("╰───────────────────────────────────────────────────────╯\n\n");
}

/*
** Here init the shell, get all environements variables, get all binaries
** and create a hashtable and create a trie data structure for autocompletion
** of binaries, set options for readline : line edition mode and history search
** mode.
** Set builtins names in the completion for binairy.
*/

void init_shell(char **env)
{
	print_welcome_message();
	set_env(env);
	set_bin(&g_shell);
	set_options();
	set_builtins();
}
