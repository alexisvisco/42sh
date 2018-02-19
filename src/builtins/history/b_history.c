/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   b_history.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 15:41:57 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 16:29:24 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "shell.h"

#define GRP_COND(x) (ft_contain_any_seq(ar, groups[x]))
#define CONTAIN_GRP(i, n) (GRP_COND(i)|| GRP_COND(n))

/*
** Parse all arguments specified in args for history command
*/

static void parse_arguments(char **args, char *ar)
{
	int i;

	args++;
	while (*args)
	{
		if (ft_strstarts_with(*args, '-'))
		{
			i = 0;
			while ((*args)[i])
			{
				if (ft_strchr(ar, (*args)[i]) == NULL &&
					ft_strchr("cdarnwe", (*args)[i]))
					ft_strcat_ch(ar, (*args)[i]);
				i++;
			}
		}
		args++;
	}
}

/*
** Check compatibility betweens each arguments
*/

static int check_errors(char *ar)
{
	const char *groups[] = {"d", "e", "canwr"};
	int        i;

	i = -1;
	while (ar[++i])
	{
		if ((ft_strchr(groups[0], *ar) && CONTAIN_GRP(1, 2)) ||
			(ft_strchr(groups[1], *ar) && CONTAIN_GRP(0, 2)) ||
			(ft_strchr(groups[2], *ar) && CONTAIN_GRP(0, 1)))
		{
			message_err(ERR_HISTORY_ARG_MERGED);
			return (1);
		}
	}
	return (0);
}

static char *get_first_arg(char **a)
{
	a++;
	while (*a)
	{
		if (!ft_strstarts_with(*a, '-'))
			return (*a);
		a++;
	}
	return (NULL);
}

/*
** Show the current history if there is no arguments
*/

int show_history(t_shell *shell)
{
	t_heap *h;
	size_t i;
	size_t j;

	if (!shell->line_edit->history_data || !shell->line_edit->history_data->heap
		|| shell->line_edit->history_data->heap->elements == 0)
	{
		message_err(ERR_NO_HISTORY);
		return (0);
	}
	h = shell->line_edit->history_data->heap;
	i = 0;
	j = 0;
	while (i < h->elements)
	{
		if (h->list[i])
		{
			ft_printf(" * %i %s\n", j + 1, (char *)h->list[i]);
			j++;
		}
		i++;
	}
	return (1);
}

/*
** Clear entierly the history
*/

static int clear_history()
{
	heap_free(HISTORY_DATA);
	HISTORY_DATA = heap_new(16);
	message(MSG_HISTORY_CLEARED);
	return (1);
}

/*
** Delete at position x the element in the history
*/

static int del_history_at(char **args)
{
	char *arg;
	char *prev;
	int  offset;


	arg = get_first_arg(args);
	if (arg == NULL)
	{
		message_err(ERR_HISTORY_OFFSET_NEEDED);
		return (0);
	}
	offset = ft_atoi(arg);
	if (offset < 0 || offset >= (int)HISTORY_DATA->elements)
	{
		message_err(ERR_HISTORY_OFFSET_INVALID, offset);
		return (0);
	}
	prev = heap_del(HISTORY_DATA, (size_t)offset);
	message(MSG_HISTORY_DELETED, offset, prev);
	free(prev);
	return (1);
}

/*
** Append the non writed history to the file or history file
*/

static int append_history(char **args)
{
	char path[2048];
	char *file;
	int  ret;

	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	file = get_first_arg(args);
	ret  = rewrite_history_file_in(HISTORY_DATA,
								   file ? file :
								   path, g_shell.line_edit->history_data->plus);
	if (ret)
	{
		message(MSG_HISTORY_APPENDED, file ? file : path);
		return (1);
	}
	else
	{
		message_err(ERR_HISTORY_APPENDED, file ? file : path);
		return (0);
	}
}

/*
** Read the line non read of the history file
*/

static int history_non_read()
{
	char path[2048];
	char *line;
	int  i;
	int  fd;

	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		message_err(ERR_HISTORY_NON_READ);
		return (0);
	}
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (i >= g_shell.line_edit->history_data->plus)
			heap_add(HISTORY_DATA, ft_strdup(line));
		free(line);
		i++;
	}
	free_gnl();
	message(MSG_HISTORY_NON_READ);
	return (1);
}

/*
** Read entirely the file and reset the history heap
*/

static int history_read(char **args)
{
	char path[2048];
	char *file;
	char *line;
	int  fd;

	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	file    = get_first_arg(args);
	if ((fd = open(file ? file : path, O_CREAT | O_RDONLY)) < 0)
	{
		message_err(ERR_HISTORY_READ, file ? file : path);
		return (0);
	}
	heap_free(HISTORY_DATA);
	HISTORY_DATA = heap_new(32);
	while (get_next_line(fd, &line))
	{
		heap_add(HISTORY_DATA, ft_strdup(line));
		free(line);
	}
	free_gnl();
	message(MSG_HISTORY_READ, file ? file : path);
	return (1);
}

/*
** Write the current history to the target file or default file
*/

static int write_history(char **args)
{
	char path[2048];
	char *file;
	int  ret;

	ft_copy_str(path, ht_get(g_shell.env, "HOME"));
	ft_strcat(path, "/"HISTORY_FILE);
	file = get_first_arg(args);
	ret  = rewrite_history_file_in(HISTORY_DATA,
								   file ? file :
								   path, 0);
	if (ret)
	{
		message(MSG_HISTORY_WRITE, file ? file : path);
		return (1);
	}
	else
	{
		message_err(ERR_HISTORY_WRITE, file ? file : path);
		return (0);
	}
}

/*
** Execute a command without adding it to the history
*/

static int history_exe(char **args)
{
	char full_str[4096];

	full_str[0] = 0;
	args++;
	while (*args)
	{
		if (!ft_strstarts_with(*args, '-'))
		{
			if (full_str[0] != 0)
				ft_strcat(full_str, " ");
			ft_strcat(full_str, *args);
		}
		args++;
	}
	char *tmp = ft_strdup(full_str);
	shell_process(tmp);
	free(tmp);
	return (1);
}

/*
** Execute a command without adding it to the history
*/

static int history_help()
{
	ft_printf("\n* history [n]\n* history -c\n* history -d offset\n* "
					  "history [-anrw] [filename]\n* history -e arg\n\n");
	ft_printf("Explanation of each arguments: \n");
	ft_printf(" -c: Clear the history list. This may be combined "
"with the other options to replace the history list completely.\n");
	ft_printf(" -d: offset: Delete the history entry at position "
"offset. offset should be specified as it appears when the history is"
					  "displayed.\n");
	ft_printf(" -a: Append the new history lines to the history f"
					  "ile.\n");
	ft_printf(" -n: Append the history lines not already read fro"
					  "m the history file to the current history list.\n");
	ft_printf(" -r: Write out the current history list to the his"
					  "tory file.\n");
	ft_printf(" -e: Perform a command without storing the results"
					  " in the history list.\n");
	return (1);
}

/*
** Redistribute with arguments, show history at index or display all history
*/

static int redistribute_action(char *ar, char **args)
{
	char *s;
	int  i;

	if (*ar)
	{
		while (*ar)
		{
			if (*ar == 'c' && !clear_history())
				return (0);
			if (*ar == 'd' && !del_history_at(args))
				return (0);
			if (*ar == 'a' && !append_history(args))
				return (0);
			if (*ar == 'n' && !history_non_read())
				return (0);
			if (*ar == 'r' && !history_read(args))
				return (0);
			if (*ar == 'w' && !write_history(args))
				return (0);
			if (*ar == 'e' && !history_exe(args))
				return (0);
			ar++;
		}
		return (1);
	}
	s = get_first_arg(args);
	if (s == NULL)
		return (show_history(&g_shell));
	i = ft_atoi(s);
	if (i >= 0 && i < (int) HISTORY_DATA->elements)
	{
		ft_printf(" * %i %s\n", i, HISTORY_DATA->list[i]);
		return (1);
	}
	return (1);
}

/*
** Show all history command that the user has typed and show the index of them
** Take no arguments
*/

int b_history(char **args, t_shell *shell)
{
	char ar[9];

	(void) shell;
	ar[0] = 0;
	if (ft_strequ(get_first_arg(args), "help"))
		return history_help();
	parse_arguments(args, ar);
	if (check_errors(ar))
		return (0);
	return (redistribute_action(ar, args));
}
