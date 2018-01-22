/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_keys.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 10:47:39 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/22 11:33:18 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

#define ISK(kecyode) (key == keycode)

static int	hook_keys(uint32_t key)
{
	return (1);
}

void		handle_keys(t_editor *e)
{
	char		*seq[5];
	uint32_t	code;

	code = 0;
	ft_memset(seq, 0, 5);
	while (read(0, seq, 5) > 0 && hook_keys((uint32_t)*seq))
	{
		code += (uint32_t)*seq;
		ft_printf("%i\n", code);
		if (code > KON)
			code = 0;
		ft_memset(seq, 0, 5);
	}
	ft_putchar_fd(e->ofd, '\n');
}