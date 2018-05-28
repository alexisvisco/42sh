/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   prompt.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/28 14:57:08 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/28 14:57:08 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <f_colors.h>
#include "shell.h"

static char	*	get_current_folder()
{
	char cwd[2048];
	char folder[2048];
	int i;
	int prev;

	if (!getcwd(cwd, sizeof(cwd)))
		return (NULL);
	i = 0;
	prev = 0;
	while (cwd[i])
	{
		if (cwd[i] == '/')
			prev = i;
		i++;
	}
	i = -1;
	while (cwd[++i])
		folder[i] = cwd[prev + (i + 1)];
	folder[i] = 0;
	return (ft_strdup(folder));
}

static char*	get_git_branch()
{
	const char	*t[] = {"/usr/bin/git", "rev-parse", "--abbrev-ref", "HEAD", NULL};

	return exec_to_str(t);
}

int	set_prompt(char *str)
{
	char *folder;
	char *branch;
	char *prompt;

	folder = get_current_folder();
	branch = get_git_branch();
	prompt = ft_sprintf("%s git:(%s) $ ", folder, branch);
	ft_copy_str(str, prompt);
	free(prompt);
	free(folder);
	free(branch);
	return (1);
}
