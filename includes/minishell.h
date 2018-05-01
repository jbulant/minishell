/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:26:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/01 01:53:43 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "libft.h"
# include "ft_error.h"
# include "msh_builtin.h"

# define PS_DEFAULT		NULL
# define ARG_KEYS(x)	x->keys[x->offset]
# define BI_COUNT		6

typedef struct s_builtin	t_builtin;
typedef enum e_ms_status	t_ms_status;
typedef struct s_argbuffer	t_argbuffer;
typedef struct s_minishell	t_minishell;
typedef struct s_env_elem	t_env_elem;

enum		e_ms_status
{
	INTERPRET = 0,
	TERMINATE = 1
};

struct		s_argbuffer
{
	char	buffer[_POSIX_ARG_MAX];
	size_t	total_size;
	char	**keys;
	char	**path;
	int		offset;
};

struct		s_minishell
{
	int			retval;
	t_list		*env;
	char		**virtual_env;
	char		**path;
	t_ms_status	status;
	t_argbuffer	*current_arg;
	int			(*action)(struct s_minishell *);
	t_builtin	*builtins;
};

int			msh_init(char **env, t_minishell *msh);

t_argbuffer	*new_argbuffer(char *str);
void		del_argbuffer(t_argbuffer **argbuffer);

int			get_usr_input(t_minishell *msh);
int			parse_input(char *input, t_minishell *msh);
int			check_builtins(t_argbuffer *arg, t_minishell *msh);

int			ft_exec_cmd(t_minishell *msh);

char		**new_virtual_env(t_minishell *msh);

void		update_path(t_minishell *msh, t_list *env);
char		*update_ps(char *ps);

/*
**				[ ENV BUILTIN ]
*/

# define ENV_ELEM(x)	((t_env_elem*)x->content)
# define ENV_OPT_I		1
# define ENV_EXEC_OPT	2
# define ENV_TMP		4

struct		s_env_elem
{
	char	content[_POSIX_ARG_MAX];
	size_t	nlen;
	size_t	total_len;
};

int			builtin_env(t_minishell *msh);

int			ft_setenv(t_minishell *msh);
int			ft_unsetenv(t_minishell *msh);

void		env_create_tmpkey(t_env_elem *elem, char *key, char *content);
char		*get_elem_key(t_env_elem *elem);
char		*get_elem_value(t_env_elem *elem);

int			env_find_replace(t_list *env, t_env_elem *elem);

int			env_setvar(t_minishell *msh, char *var, char *value);
t_env_elem	*get_env_elem(t_list *env, char *name, size_t nlen);
t_env_elem	*new_env_elem(char *elem);
t_bool		env_elem_cmp(t_env_elem *e1, t_env_elem *e2);
void		env_elem_update(t_env_elem *ret, char *elem);
int			replace_elem(t_list *lst, char *value);
t_list		*search_elem(t_list *env, char *key);

char		**env_toarray(t_list *env);

/*
**			[ CD BUILTINS ]
*/

int			ft_cd(t_minishell *msh);

int			goto_fname(t_minishell *msh, char *path);
int			env_gotovar(t_minishell *msh, char *var);

/*
**			[ VARIOUS BUILTINS ]
*/

int			ft_echo(t_minishell *msh);
int			sh_exit(t_minishell *msh);

#endif
