/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_token.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 01:03:26 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/26 05:19:59 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_TOKEN_H
# define MSH_TOKEN_H

# include "libft.h"
# include "ft_stack.h"

# define TOKEN_DEBUG 1
# define TOKEN_HEIGHT	50

typedef enum	e_tkn_type
{
	WORD = 0,
	SEMICOLON = 1
}				t_tkn_type;

typedef struct	s_token
{
	struct s_token	*next;
	char			*content;
	size_t			content_size;
	t_tkn_type		type;
}				t_token;

typedef struct	s_inblock
{
	char	*input;
	size_t	input_len;
	char	**argv;
	size_t	argv_len;
	char	**env;
}				t_inblock;

typedef struct	s_usr_input
{
	char		*buffer;
	size_t		buff_len;
	t_list		*get;
	size_t		get_cnt;
	t_token		*token;
	size_t		token_cnt;
	t_stack		exec;
}				t_usr_input;

t_token		*tkn_new(char *content, t_tkn_type type);
void		tkn_add(t_token **head, t_token *nxt);

void		usr_input_init(t_usr_input *input);
void		usr_input_reinit(t_usr_input *input);

#endif
