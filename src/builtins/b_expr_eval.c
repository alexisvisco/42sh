/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_expr_eval.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:35:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 10:37:56 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"

static int	is_end(char *cmp, char *line)
{
	t_res	res;

	if (ft_strequ(cmp, line))
		return (1);
	res.error = NULL;
	eval_expr(line, &res);
	if (res.error)
		ft_printf("Error: %s\n", res.error);
	else ft_printf("%i\n", res.res);
	ft_memdel((void **)&(res.error));
	return (0);
}

int			b_expr_eval(char **args, t_shell *shell)
{
	t_heap *tmp;

	(void)args;
	(void)shell;
	ft_printf("Type `exit` to quit this prompt.\n");
	tmp = ask_line("(calc) ", 0, is_end, "exit");
	heap_free(tmp);
	return (1);
}
