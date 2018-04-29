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


static int	pop_stack_i(t_stack_i *stack)
{
	return stack->data[--stack->top];
}

static int	peek_stack_i(t_stack_i *stack)
{
	if (stack->top == 0)
		return 0;
	return stack->data[stack->top - 1];
}

static void push_stack_i(t_stack_i *stack, int c)
{
	stack->data[stack->top++] = c;
}

void init_stack_i(t_stack_i *stack)
{
	stack->top  = 0;
	stack->pop  = pop_stack_i;
	stack->peek = peek_stack_i;
	stack->push = push_stack_i;
	for (int i  = 0; i < 4096; ++i)
		stack->data[i] = 0;
}