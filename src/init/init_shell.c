/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_shell.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/31 18:49:36 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/31 20:46:49 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "f_colors.h"

static void	print_welcome_message()
{
	const char		*message = "Welcome to our shell (by ggranjon & aviscogl)";
	const size_t	len = ft_strlen(message);
	const size_t	len_tr = 54;
	ft_printf("\n╭───────────────────────────────────────────────────────╮\n");
	ft_printf("│%*s│\n", len_tr + 1, " ");
	ft_printf("│%s%*s%-*s%s│\n", CYAN,
	len + ((len_tr - len)/2) + 1, message,
	((len_tr - len)/2) + ((len % 2 == 0) ? 0 : 1), " ", RESET_ALL);
	ft_printf("│%*s│\n", len_tr + 1, " ");
	ft_printf("╰───────────────────────────────────────────────────────╯\n\n");
}

void	init_shell()
{
	print_welcome_message();
	set_env();
	set_bin();
	set_options();
}
