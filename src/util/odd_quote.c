/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   odd_quote.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 14:47:56 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 11:22:57 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

int		which_quote(char *s)
{
	int i;
	int simple_q;

	i = 0;
	simple_q = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			simple_q++;
		i++;
	}
	return (simple_q % 2 == 0 ? -3 : -2);
}

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

void	odd_quote_prompt(t_token ***tokens, char *s)
{
	char	*new_line;
	char	*tmp;
	int		quote;

	free(*tokens);
	quote = which_quote(s);
	new_line = heap_to_str(ask_line("dquote> ", 1, odd_quote,
	quote == -3 ? "\"" : "\'"));
	tmp = new_line;
	new_line = ft_strjoin(s, new_line);
	free(tmp);
	g_shell.line = new_line;
	free(s);
	shell_process(multi_line_prompt(new_line, 1));
}
