/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   exec.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 17:26:58 by ggranjon     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 19:03:10 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>

int			end_of_arg(t_token **tokens, t_block *block, int num);
char		**extract_cmd_args(t_token **tokens, t_block *block, int num);

int			analyze_next_and_or(t_token **tokens, int index);
char		**next_cmd(t_token **tokens, t_block *block, int num, int index);

int			go_next_index(t_token **tokens, t_block *blocks, int num[2]);
int			go_to_next(t_token **tokens, t_block *block, int num, int index);
int			exec_or_and(t_token **tokens, t_block *blocks, int num[2], int ret);

int			fork_result(char *node, char **argv);
void		exec_all(t_token **tokens, t_block *blocks);
void		exec_a_block(char **argv);

void		sig_handler(int signo);

#endif
