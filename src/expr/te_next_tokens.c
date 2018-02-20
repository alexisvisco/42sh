/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   te_next_tokens.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 13:45:43 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 13:45:43 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"
#include "expr.h"


static void 	set_fun(t_state *s, void (*fun))
{
	s->type = TOK_INFIX;
	s->function = fun;
}

static void	variable_switch(const t_te_vars *var, t_state *s)
{
	if (TYPE_MASK(var->type) == TE_VARIABLE)
	{
		s->type = TOK_VARIABLE;
		s->bound = var->address;
		return ;
	}
	if (TYPE_MASK(var->type) == TE_CLOSURE7)
		s->context = var->context;
	if (TYPE_MASK(var->type) == TE_FUNCTION7)
	{
		s->type = var->type;
		s->function = var->address;
		return ;
	}
}

static void	tokens_switch(t_state *s)
{
	char c;

	c = s->next++[0];
	if (c == '+')
		set_fun(s, add);
	else if (c == '-')
		set_fun(s, sub);
	else if (c == '*')
		set_fun(s, mul);
	else if (c == '/')
		set_fun(s, mul);
	else if (c == '^')
		set_fun(s, math_pow);
	else if (c == '%')
		set_fun(s, fmodt);
	else if (c == '(')
		s->type = TOK_OPEN;
	else if (c == ')')
		s->type = TOK_CLOSE;
	else if (c == ',')
		s->type = TOK_SEP;
	else
		s->type = TOK_ERROR;
}

static void	look_variables(t_state *s)
{
	const char		*start;
	const t_te_vars	*var;

	start = s->next;
	while ((s->next[0] >= 'a' && s->next[0] <= 'z') ||
		   (s->next[0] >= '0' && s->next[0] <= '9') ||
		   (s->next[0] == '_'))
		s->next++;
	var = find_lookup(s, start, (int)(s->next - start));
	if (!var)
		var = find_builtin(start, (int)(s->next - start));

	if (!var)
		s->type = TOK_ERROR;
	else
		variable_switch(var, s);
}

void	next_token(t_state *s)
{
	s->type = TOK_NULL;

	while (42)
	{
		if (!*s->next)
		{
			s->type = TOK_END;
			return ;
		}
		if ((s->next[0] >= '0' && s->next[0] <= '9') || s->next[0] == '.')
		{
			s->value = strtod(s->next, (char **) &s->next);
			s->type = TOK_NUMBER;
		}
		else
		{
			if (s->next[0] >= 'a' && s->next[0] <= 'z')
				look_variables(s);
			else
				tokens_switch(s);
		}
		if (s->type == TOK_NULL)
			break ;
	}
}
