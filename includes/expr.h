/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expr.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 11:15:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 11:15:54 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EXPR_H
# define EXPR_H

# include <stdlib.h>
# include <stdio.h>
# include <libft.h>

# define ALLOWEDS_CHARS(c) (strchr("+-*/%() 0123456789", c) != NULL)

typedef struct	result_expr
{
	int 		res;
	char 		*error;
}				t_res;

int		parse_sum(char **expr, t_res *res);
int		can_exec(t_res *res, int number);
int		custom_atoi(char **str);
void	eval_expr(char *expr, t_res *res);
int		valid_expr(char *expr);

#endif
