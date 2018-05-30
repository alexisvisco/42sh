/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   odd_quote.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 14:47:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 13:45:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		odd_quote(char *quote, char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == *quote)
			count++;
		i++;
	}
	return (count % 2);
}

char    which_quote(char *s)
{
	int simple_q;
	int double_q;

	simple_q = 0;
	double_q = 0;
	while (*s)
	{
		if (*s == '\'')
			simple_q++;
		else if (*s == '\"')
			double_q++;
		s++;
	}
	if (simple_q % 2)
		return ('\'');
	else if (double_q % 2)
		return ('\"');
	else
		return ('`');
}

void    odd_quote_prompt(t_token ***tokens, char *s)
{
	char    *new_line;
	char    *tmp;
	char 	*quote;

	free(*tokens);
	quote = ft_char_to_str(which_quote(s));
	new_line = heap_to_str(ask_line("dquote> ", !ft_strequ(quote, "`"),
	odd_quote, quote), !ft_strequ(quote, "`"));
	free(quote);
	tmp = new_line;
	new_line = ft_strjoin(s, new_line);
	free(tmp);
	g_shell.line = new_line;
	free(s);
	shell_process(multi_line_prompt(new_line, 0));
}

