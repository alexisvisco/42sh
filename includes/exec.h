/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 17:26:58 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/15 11:52:09 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define EXEC_FINISH	18
# define READ_END		0
# define WRITE_END		1

typedef struct	s_fd
{
	int			save;
	int			output;
	int			input;
}				t_fd;

int				analyze_next_and_or(char *s);

char			**extract_cmd(t_token **tokens, int *index);

int				is_executable(char *path);
int				call_right_redir(char ***cmds);
int				call_left_redir(char ***cmds);
int				call_heredoc(char ***cmds, int fd2);

int				analyze_agreg(char ***cmds);
int				call_ag_redir(char ***cmds);
int				delete_redir_and_dup(char ***cmds, int file);

int				open_files(char ***cmds);

int				exec_cmds(char ***argv, t_block *blocks, t_token **tokens);
char			***extract_all_pipes(char **argv);

int				exec_next_index(t_token **tokens, t_block *blocks,
				int *num, int ret);
int				go_to_next(t_token **tokens, t_block *block,
				int num, int index);
int				exec_or_and(t_token **tokens, t_block *blocks,
				int num[2], int ret);

int				replace_argv0_by_exec(char ***cmds);

void			sig_handler(int signo);

#endif
