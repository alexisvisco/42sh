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
#include "libft.h"

#define OPS "-+/*^"
#define RIGHT "^"
#define LEFT "*/+-"
#define P_4  "^"
#define P_3  "*/"
#define P_2  "+-"

typedef struct  stack
{
    char        data[4096];
    int         top;
    char        (*pop)(struct stack *);
    char        (*peek)(struct stack *);
    void        (*push)(struct stack *, char);
}               t_stack;

void lookup(const char *str, int i, char **postfix, struct stack *stack);

char    pop_stack(t_stack *stack)
{
    char c = stack->data[--stack->top];
    return c;
}

char    peek_stack(t_stack *stack)
{
    if (stack->top == 0)
        return 33;
    return stack->data[stack->top - 1];
}

void    push_stack(t_stack *stack, char c)
{
    stack->data[stack->top++] = c;
}

void    init_stack(t_stack *stack) {
    stack->top = 0;
    stack->pop = pop_stack;
    stack->peek = peek_stack;
    stack->push = push_stack;
    for (int i = 0; i < 4096; ++i) {
        stack->data[i] = 33;
    }
}

void    add_to_postfix(char **src, char c, int space) {
    char *tmp;
    char *to_free;

    if (c != 33 && c != '(') {
        tmp = space ? ft_sprintf("%c ", c) : ft_char_to_str(c);
        to_free = *src;
        *src = ft_strjoin(*src, tmp);
        free(to_free);
        free(tmp);
    }
}

int     get_precedence(char c) {
    if (ft_strchr(P_4, c))
        return 4;
    if (ft_strchr(P_3, c))
        return 3;
    if (ft_strchr(P_2, c))
        return 2;
    return -1;
}

int     get_cond(char o1, char o2) {
    int is_left = ft_strchr(LEFT, o1) != NULL;
    int is_right = ft_strchr(RIGHT, o1) != NULL;
    int inf_or_equ = get_precedence(o1) <= get_precedence(o2);
    int inf = get_precedence(o1) < get_precedence(o2);
    return (is_left && inf_or_equ) || (is_right && inf);
}

void lookup(const char *str, int i, char **postfix, struct stack *stack) {
    const char o1 = str[i];
    char o2;

    o2 = (*stack).peek(stack);
    while (ft_strchr(OPS, o2) && get_cond(o1, o2))
    {
        add_to_postfix(postfix, o2, 1);
        (*stack).pop(stack);
        o2 = (*stack).peek(stack);
    }
    (*stack).push(stack, str[i]);
}

void    add_remaining(char **postfix, struct stack *stack) {
    while ((*stack).top >= 0) {
        add_to_postfix(postfix, (*stack).data[(*stack).top], 1);
        (*stack).top--;
    }
}

char    *to_npi(char *str)
{
    char *postfix;
    struct stack stack;
    int i;


    init_stack(&stack);
    postfix = ft_strdup("");
    i = -1;
    while (str[++i] != 0)
    {
        if (ft_isdigit(str[i]))
            add_to_postfix(&postfix, str[i], 1);
        else if (ft_strchr(OPS, str[i]))
            lookup(str, i, &postfix, &stack);
        else if (str[i] == ')')
        {
            while (stack.peek(&stack) != '(')
                add_to_postfix(&postfix, stack.pop(&stack), 1);
            stack.pop(&stack);
        }
    }
    add_remaining(&postfix, &stack);
    return postfix;
}

