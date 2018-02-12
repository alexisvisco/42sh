/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lex.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ggranjon <ggranjon@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/19 12:54:48 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 09:27:52 by aviscogl    ###    #+. /#+    ###.fr     */
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

typedef struct	s_token
{
	char		*value;
	t_tok_type	type;
	int			index;
}				t_token;

typedef enum	e_block_type
{
	NOTHING = 0,
	TY_REDIR,
	TY_AND,
	TY_OR
}				t_block_type;

/*
** isredir[0] = typedef block_type
** isredir[1] is for the type of the redir :
** 	0 =  "3>&2" even if isredir[0] = 0
**	1 = "<<"
**	2 = "<"
**	3 = ">"
**	4 = ">>"
*/

typedef struct	s_block
{
	int				start_tok;
	int				end_tok;
	int				isredir[2];
	t_block_type	my_op[64];
	int				nb_pipe;
}				t_block;

char			*cpy_special(char *s);
int				count_tokens(char *s);
t_token			**split_tokens(char *s, int nbtokens);

int				lex_all(t_token ***tokens, char *s);
int				analyze_sep(t_token **tokens);

int				is_commentary(t_token **tokens);
t_block			*extract_block_commentary(t_token **tokens, int nb_tokens);

t_block			*extract_blocks(t_token **tokens);
int				analyze_block(t_block **blocks, t_token **tokens);

char			*remove_quotes(char *s);
char			*change_quotes(char *s);
void			format_tokens_quotes(t_token ***tokens);

void			extract_type_redir(t_token **tokens, t_block **block);
void			analyze_or_and(t_block **block, t_token **tokens);
int				operator_error(t_block **blocks, t_token **tokens);

int				parse_tokens(t_token ***tokens, char *s);
int				parse_block(t_token **tokens, t_block **blocks);

#endif
