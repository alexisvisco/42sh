/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   readline_notty.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/21 09:49:19 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 10:08:06 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "editor.h"

/*
** This function is called when readline() is called with the standard
** input file descriptor not attached to a TTY (a terminal). So for example
** when the program using readline is called in pipe or with a file redirected
** to its standard input. In this case, we want to be able to return the
** line regardless of its length (by default we are limited to 4k).
** > fgetc: used because we want to read the stream flux.
*/

char	*readline_notty()
{
	char	*line;
	char	*old_val;
	size_t	len;
	size_t	maxlen;
	int		c;

	line = NULL;
	len = 0;
	maxlen = 0;
	while (1)
	{
		if (maxlen == len)
		{
			if (maxlen == 0)
				maxlen = 16;
			maxlen *= 2;
			old_val = line;
			line = ft_realloc(line, maxlen);
			if (line == NULL)
			{
				if (old_val)
					free(old_val);
                return NULL;
			}
		}
		c = fgetc(stdin);
		if (c == EOF || c == '\n')
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
		else
		{
			line[len] = c;
			len++;
		}
	}
}