/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   builtins.h                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/05 18:45:07 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/13 15:39:39 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "shell.h"

typedef int(t_builtins_fun)(char **, t_shell *);

t_builtins_fun	*builtins(char *cmd);
t_builtins_fun	*builtins_env(char *cmd);

t_hashtable		*get_builtins();
t_hashtable		*get_builtins_env(void);

int				b_pwd(char **args, t_shell *shell);
int				b_env(char **args, t_shell *shell);
int				b_echo(char **args, t_shell *shell);
int				b_history(char **args, t_shell *shell);
int				b_cd(char **args, t_shell *shell);
int				b_env_set(char **args, t_shell *shell);
int				b_env_unset(char **args, t_shell *shell);
int				b_clear(char **args, t_shell *shell);
int				b_exit(char **args, t_shell *shell);
int				b_search_binary(char **args, t_shell *shell);
int				b_set_last_history(char **args, t_shell *shell);
int				b_set_history_contain(char **args, t_shell *shell);
int				b_set_history_start(char **args, t_shell *shell);
int				b_set_history_from_n_last(char **args, t_shell *shell);
int				b_set_history_from_n(char **args, t_shell *shell);
t_builtins_fun	*b_history_handler(char *cmd);

#endif
