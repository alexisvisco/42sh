/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   eval_expr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 09:38:54 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 10:14:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"


static const t_te_vars functions[] =
		{
				{"abs", math_abs, TE_FUNCTION1 | TE_FLAG_PURE, 0},
				{"e", e, TE_FUNCTION0 | TE_FLAG_PURE, 0},
				{"fac", fac, TE_FUNCTION1 | TE_FLAG_PURE, 0},
				{"ncr", ncr, TE_FUNCTION2 | TE_FLAG_PURE, 0},
				{"npr", npr, TE_FUNCTION2 | TE_FLAG_PURE, 0},
				{"pgcd", math_pgcd, TE_FUNCTION2 | TE_FLAG_PURE, 0},
				{"pi", pi, TE_FUNCTION0 | TE_FLAG_PURE, 0},
				{"pow", math_pow, TE_FUNCTION2 | TE_FLAG_PURE, 0},
				{"sqrt", math_sqrt, TE_FUNCTION2 | TE_FLAG_PURE, 0},
				{0, 0, 0, 0}
		};


t_expr *
te_compile(const char *expression, const t_te_vars *variables, int var_count,
		   int *error)
{
	t_state s;
	s.start = s.next = expression;
	s.lookup = variables;
	s.lookup_len = var_count;

	next_token(&s);
	t_expr *root = list(&s);

	if (s.type != TOK_END)
	{
		te_free(root);
		if (error)
		{
			*error = (s.next - s.start);
			if (*error == 0) *error = 1;
		}
		return 0;
	}
	else
	{
		optimize(root);
		if (error) *error = 0;
		return root;
	}
}


double te_interp(const char *expression, int *error)
{
	t_expr *n = te_compile(expression, 0, 0, error);
	double ret;
	if (n)
	{
		ret = te_eval(n);
		te_free(n);
	}
	else
	{
		ret = NAN;
	}
	return ret;
}