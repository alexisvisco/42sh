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

#include "shell.h"

static char	*get_current_folder(void)
{
	char	cwd[2048];
	char	*tmp;
	char	**ta;

	if (!get_cwd(cwd, sizeof(cwd)))
		return (ft_strdup("unknown"));
	ta = ft_strsplit(cwd, '/');
	if (!ta)
		return (ft_strdup("/"));
	if (size_tab(ta) == 0)
	{
		free_tab(ta);
		return (ft_strdup("/"));
	}
	else
	{
		tmp = ft_strdup(ta[size_tab(ta) - 1]);
		free_tab(ta);
		return (tmp);
	}
}

static char	*get_git_branch(void)
{
	const char	*t[] = {"/usr/bin/git", "rev-parse", "--abbrev-ref",
	"HEAD", NULL};

	return (exec_to_str(t));
}

int			set_prompt(char *str)
{
	char *folder;
	char *branch;
	char *prompt;

	folder = get_current_folder();
	branch = get_git_branch();
	ft_bzero(str, 256);
	if (!branch || !(*branch))
		prompt = ft_sprintf("%s $ ", folder, branch);
	else
		prompt = ft_sprintf("%s git:(%s) $ ", folder, branch);
	ft_copy_str(str, prompt);
	ft_memdel((void **)&prompt);
	ft_memdel((void **)&folder);
	ft_memdel((void **)&branch);
	return (1);
}
