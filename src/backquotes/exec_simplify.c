/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec_simplify.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/05 10:51:26 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/06/05 10:51:26 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

void			get_backq_string(const int *p, t_backquotes *ret)
{
	char *line;
	char *tmp;

	while (get_next_line(p[READ_END], &line) > 0)
	{
		tmp = (*ret).str;
		(*ret).str = ft_mine_strjoin((*ret).str, line);
		ft_memdel((void **)&tmp);
		ft_memdel((void **)&line);
	}
	free_gnl();
}

t_backquotes	error_redir(t_backquotes *ret)
{
	(*ret).status = 1;
	(*ret).str = NULL;
	return (*ret);
}

void			get_backq_status(int status, t_backquotes *ret)
{
	while (wait(NULL) > 0)
		;
	(*ret).status = WEXITSTATUS(status);
	(*ret).str = ft_strnew(1);
}
