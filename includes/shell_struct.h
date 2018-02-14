/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shell_struct.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 12:17:33 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 13:59:09 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SHELL_STRUCT_H
# define SHELL_STRUCT_H

# include "libft.h"
# include "editor.h"

typedef struct	s_shell
{
	t_hashtable	*env;
	t_hashtable	*bin;
	t_trie_node	*bin_trie;
	t_trie_node	*env_trie;
	t_options	*line_edit;
	t_options	*history_search;
	char		*line;
	char		***cmds;
}				t_shell;

#endif
