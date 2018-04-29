/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   stack.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/20 09:05:01 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 09:05:01 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <expr.h>


static char *pop_stack(t_stack *stack)
{
	return stack->data[--stack->top];
}

static char *peek_stack(t_stack *stack)
{
	if (stack->top == 0)
		return NULL;
	return stack->data[stack->top - 1];
}

static void push_stack(t_stack *stack, char *c)
{
	stack->data[stack->top++] = c;
}

void init_stack(t_stack *stack)
{
	stack->top  = 0;
	stack->pop  = pop_stack;
	stack->peek = peek_stack;
	stack->push = push_stack;
	for (int i  = 0; i < 4096; ++i)
	{
		stack->data[i] = NULL;
	}
}