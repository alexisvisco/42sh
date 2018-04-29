/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_expr_npi.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 10:50:34 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 10:50:34 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "util.h"
#include "expr.h"


int priority(char c)
{
	if (c == '^')
		return 3;
	if (c == '*')
		return 2;
	if (c == '/')
		return 2;
	if (c == '+')
		return 1;
	if (c == '-')
		return 1;
	return 0;
}

void	append(char **str, char *to_append, int free_ap) {
	char *tmp;

	tmp = *str;
	*str = ft_strjoin(*str, to_append);
	free(tmp);
	if (free_ap)
		free(to_append);
}

/*
** Return 1 = ended
** Else return a string (numbers or ops)
*/

char *next_token(int *i, char *expr) {
	const int size = (const int)ft_strlen(expr);
	char *res;

	while (*i < size && expr[*i] == ' ')
		(*i)++;
	if (*i == size)
		return ft_char_to_str(1);
	res = ft_strdup("");
	while (*i < size && expr[*i] != ' ' && expr[*i] != '(' && expr[*i] != ')' &&
			!IS_OP(expr[*i]))
		append(&res, ft_char_to_str(expr[(*i)++]), 1);
	if (!ft_strequ("", res))
		return res;
	free(res);
	return ft_char_to_str(expr[(*i)++]);
}

char *result_string(t_stack *o)
{
	char *res;
	int  x;

	res = ft_strdup("");
	x = 0;
	while (x < (*o).top) {
		if (x != 0)
			append(&res, " ", 0);
		append(&res, (*o).data[x], 1);
		x++;
	}
	return res;
}

char *infix2postfix(char *str)
{
	t_stack s;
	t_stack o;
	int 	i;
	char 	*tok;


	i = 0;
	init_stack(&s);
	init_stack(&o);
	while ((tok = next_token(&i, str))[0] != 1)
	{
		if (tok[0] == '(')
			s.push(&s, ft_char_to_str('('));
		else if (tok[0] == ')')
		{
			while (s.top > 0 && s.peek(&s)[0] != '(')
				o.push(&o, s.pop(&s));
			if (s.top == 0) return NULL; //mismatch parentheses
			free(s.pop(&s));
		}
		else if (IS_OP(tok[0]))
		{
			while (s.top > 0 && IS_OP(s.peek(&s)[0]) &&
	((IS_LEFT(tok[0]) && priority(tok[0]) <= priority(s.peek(&s)[0])) ||
	(!IS_LEFT(tok[0]) && priority(tok[0]) < priority(s.peek(&s)[0]))))
				o.push(&o, s.pop(&s));
			s.push(&s, ft_strdup(tok));
		}
		else
			o.push(&o, ft_strdup(tok));
		free(tok);
	}
	free(tok);

	while (s.top > 0) {
		if (!IS_OP(s.peek(&s)[0]))
			return NULL; //mismatch parentheses
		o.push(&o, s.pop(&s));
	}

	if (o.top == 0)
		return NULL; //invalid expression

	return result_string(&o);
}

