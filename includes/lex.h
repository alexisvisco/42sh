/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lex.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:48 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/20 17:49:57 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# define FT_SEP		"&|;"
# define FT_REDIR	"><"

typedef enum	e_tok_type
{
				COMMAND,
				PIPE,
				ARG,
				IO_REDIRECT,
				SEPARATOR_OP,
				FD
}				t_tok_type;

typedef struct	s_token
{
	char 		*value;
	t_tok_type	type;
}				t_token;

char			*ft_specpy(char *s);
int				ft_counttoken(char *s);
t_token			**ft_splittokens(char *s);

void			ft_lexall(t_token ***tokens, char *s);
char			*ft_removeq(char *s);

#endif