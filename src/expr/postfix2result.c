/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   postfix2result.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 11:10:00 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 11:10:00 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "expr.h"
#include "util.h"


int inteqstr(int i, char *s)
{
	const char *to_str = ft_sprintf("%i", i);
	const int  res     = ft_strequ(to_str, s);
	free((void *) to_str);
	return res;
}

int exec_ops(char *const *splitted, t_stack_i *stack,
			t_res_npi *res, int i)
{
	const int o2 = stack->pop(stack);
	const int o1 = stack->pop(stack);

	if (splitted[i][0] == '+')
		stack->push(stack, o1 + o2);
	if (splitted[i][0] == '-')
		stack->push(stack, o1 - o2);
	if (splitted[i][0] == '*')
		stack->push(stack, o1 * o2);
	if (splitted[i][0] == '^')
		stack->push(stack, math_pow(o1, o2));
	if (splitted[i][0] == '/')
	{
		if (o2 == 0)
		{
			res->error = ft_strdup("Infinity.");
			return 0;
		}
		stack->push(stack, o1 / o2);
	}
	return 1;
}

void loop(char *const *splitted, t_stack_i *stack, t_res_npi *res)
{
	int i;
	int n;

	i = -1;
	while (splitted[++i])
	{
		ft_printf("hey\n");
		n = ft_atoi(splitted[i]);
		if (inteqstr(n, splitted[i]))
			stack->push(stack, n);
		else
		{
			if (!IS_OP(splitted[i][0]))
			{
				res->error = ft_strdup("Unknown operator.");
				return;
			}
			else if (stack->top < 2)
			{
				res->error = ft_strdup("Insufficient operands.");
				return;
			}
			else
				if (!exec_ops(splitted, stack, res, i))
					return;

		}
	}
	ft_printf("\nres: %i\n", stack->peek(stack));
	res->res = stack->pop(stack);
}

void postfix2result(char *str, t_res_npi *res)
{
	t_stack_i stack;
	char      **splitted;

	init_stack_i(&stack);
	splitted = ft_split(str, " \t\n\r\v\f");
	res->error = NULL;
	loop(splitted, &stack, res);
}