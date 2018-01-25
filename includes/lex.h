/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lex.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:48 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/25 17:09:45 by ggranjon    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# define FT_SEP		"&|;"
# define FT_REDIR	"><"
# define S			"(s + 1)"

typedef enum	e_tok_type
{
	COMMAND,
	ARG,
	IO_REDIR,
	SEP_OP,
	FD_FILE
}				t_tok_type;

/*
typedef enum	e_tok_type
{
	ZERO,
	ARG,
	IO_REDIR,
	SEP_OP,
	FD_FILE
}				t_;*/


typedef struct	s_token
{
	char		*value;
	t_tok_type	type;
	int			index;
}				t_token;


typedef struct	s_block
{
	int			start_tok;
	int			end_tok;
	int			isredir[2];
}				t_block;

char			*specpy(char *s);
int				count_tokens(char *s);
t_token			**split_tokens(char *s, int nbtokens);

int				ft_lexall(t_token ***tokens, char *s);

t_block			*extractblock(t_token **tokens);

int				analyze_block(t_block **blocks, t_token **tokens);

char			*remove_quotes(char *s);
char			*change_quotes(char *s);
void			format_tokens_quotes(t_token ***tokens);

#endif
