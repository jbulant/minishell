/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:26:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/26 16:45:17 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <limits.h>
# include "libft.h"
# include "ft_pmatch.h"
# include "ft_error.h"
# include "get_next_line.h"
#include "msh_builtin.h"
#include "msh_token.h"

# define BI_COUNT		5

typedef struct s_builtin	t_builtin;

typedef enum e_ms_status
{
	INTERPRET = 0,
	LEX = 1,
	PARS = 2,
	EXEC = 3,
	TERMINATE = 4
}			t_ms_status;

typedef struct	s_argbuffer
{
	char	buffer[_POSIX_ARG_MAX];
	size_t	total_size;
	char	**keys;
}				t_argbuffer;

typedef struct	s_minishell
{
	t_list			*env;
	char			**virtual_env;
	char			**path;
	t_ms_status		status;
	t_usr_input		input;
	t_argbuffer		*current_arg;
	int				(*action)(struct s_minishell *);
	t_builtin		*builtins;
}				t_minishell;

int				msh_init(char **env, t_minishell *msh);

t_argbuffer		*new_argbuffer(char *str);
void			del_argbuffer(t_argbuffer **argbuffer);

int				get_usr_input(t_minishell *msh);
int				parse_input(char *input, t_minishell *msh);
int				check_builtins(t_argbuffer *arg, t_minishell *msh);

int				ft_exec_cmd(t_minishell *msh);

/*
**				[ ENV BUILTIN ]
*/

#define ENV_ELEM(x)		((t_env_elem*)x->content)

typedef struct	s_env_elem
{
	char		content[4096];
	size_t		nlen;
	size_t		total_len;
}				t_env_elem;

int				builtin_env(t_minishell *msh);

int				ft_setenv(t_minishell *msh);
int				ft_unsetenv(t_minishell *msh);

char			*get_elem_key(t_env_elem *elem);
char			*get_elem_value(t_env_elem *elem);

t_env_elem		*get_env_elem(t_list *env, char *name, size_t nlen);
t_env_elem		*new_env_elem(char *elem);
t_bool			env_elem_cmp(t_env_elem *e1, t_env_elem *e2);
void			env_elem_update(t_env_elem *ret, char *elem);
int				replace_elem(t_list *lst, char *value);
t_list			*search_elem(t_list *env, char *key);

void			update_path(t_minishell *msh);

char			**env_toarray(t_list *env);
/*
**			[ VARIOUS BUILTINS ]
*/

int				ft_echo(t_minishell *msh);
int				sh_exit(t_minishell *msh);

#endif
