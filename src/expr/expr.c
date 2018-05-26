/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   expr.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 11:05:03 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/26 11:05:03 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <expr.h>


int		parse_number(char **expr, t_res *res)
{
	int nbr;

	while (**expr == ' ')
		(*expr)++;
	if (**expr == '(')
	{
		(*expr)++;
		nbr = parse_sum(expr, res);
		if (**expr == ')')
			(*expr)++;
		return (nbr);
	}
	return (custom_atoi(expr));
}

int parse_factors(char **expr, t_res *res)
{
	int		nbr;
	int		nbr2;
	char	op;

	nbr = parse_number(expr, res);
	while (**expr)
	{
		if (res->error != NULL) return 0;
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '/' && op != '*' && op != '%')
			return (nbr);
		(*expr)++;
		nbr2 = parse_number(expr, res);
		if (op == '/' && can_exec(res, nbr2))
			nbr /= nbr2;
		else if (op == '*')
			nbr *= nbr2;
		else if (can_exec(res, nbr2))
			nbr %= nbr2;
	}
	return (nbr);
}

int parse_sum(char **expr, t_res *res)
{
	int		nbr;
	int		nbr2;
	char	op;

	nbr = parse_factors(expr, res);
	while (**expr)
	{
		if (res->error != NULL) return 0;
		while (**expr == ' ')
			(*expr)++;
		op = **expr;
		if (op != '+' && op != '-')
			return (nbr);
		(*expr)++;
		nbr2 = parse_factors(expr, res);
		if (op == '+')
			nbr += nbr2;
		else
			nbr -= nbr2;
	}
	return (nbr);
}

void	eval_expr(char *expr, t_res *res)
{
	res->error = NULL;
	res->res = parse_sum(&expr, res);
}