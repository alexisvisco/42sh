/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   multi_line.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 16:16:15 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 18:23:55 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "shell.h"

static int	is_end_multiline(char *cmp, char *line)
{
	(void)cmp;
	return (!ft_strends_with(line, '\\'));
}

char		*multi_line_prompt(char *line, int free_line)
{
	char *tmp;
	char *res_ml;

	if (ft_strends_with(line, '\\'))
	{
		line[ft_strlen(line) - 1] = 0;
		tmp = line;
		res_ml = heap_to_str_rm_one(ask_line("> ", 0, is_end_multiline, NULL));
		line = ft_strjoin(line, res_ml);
		if (free_line)
			free(tmp);
		free(res_ml);
	}
	return (line);
}
