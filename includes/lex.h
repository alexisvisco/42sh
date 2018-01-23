/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lex.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:48 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/23 15:55:49 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# define FT_SEP		"&|;"
# define FT_REDIR	"><"
# define S			"(s + 1)"
# define SPLITCMD	"&;"

typedef enum	e_tok_type
{
	COMMAND,
	ARG,
	IO_REDIR,
	SEP_OP,
	FD_FILE
}				t_tok_type;

typedef struct	s_token
{
	char		*value;
	t_tok_type	type;
	int			index;
}				t_token;
/*
typedef struct	s_underbCO
{
	int			start_tok;
	int			end_tok;
}				t_underb;*/

typedef struct	s_block
{
	int			start_tok;
	int			end_tok;
}				t_block;

char			*ft_specpy(char *s);
int				ft_counttoken(char *s);
t_token			**ft_splittokens(char *s, int nbtokens);

void			ft_lexall(t_token ***tokens, char *s);
char			*ft_removeq(char *s);

t_block		*extractblock(t_token **tokens);

#endif