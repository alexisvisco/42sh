/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readline_notty.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 09:49:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 13:59:31 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

static char	*readline_tty_end(char c, size_t len, char *line)
{
	if (c == EOF && len == 0)
	{
		free(line);
		return (NULL);
	}
	else
	{
		line[len] = '\0';
		return (line);
	}
}

static void	readline_notty_aux(size_t maxlen, char *old_val, char *line)
{
	if (maxlen == 0)
	{
		maxlen = 16;
		maxlen *= 2;
		old_val = line;
		line = ft_realloc(line, maxlen);
		if (line == NULL)
		{
			if (old_val)
				free(old_val);
		}
	}
}

/*
** This function is called when readline() is called with the standard
** input file descriptor not attached to a TTY (a terminal). So for example
** when the program using readline is called in pipe or with a file redirected
** to its standard input. In this case, we want to be able to return the
** line regardless of its length (by default we are limited to 4k).
** > fgetc: used because we want to read the file or piped stream flux.
*/

char		*readline_notty(void)
{
	char	*line;
	char	*old_val;
	size_t	len;
	size_t	maxlen;
	int		c;

	line = NULL;
	len = 0;
	old_val = NULL;
	maxlen = 0;
	while (1)
	{
		if (maxlen == len)
		{
			readline_notty_aux(maxlen, old_val, line);
			if (line == NULL)
				return (NULL);
		}
		if ((c = fgetc(stdin)) && (c == EOF || c == '\n'))
			return (readline_tty_end(c, len, line));
		else
			line[len++] = c;
	}
}
