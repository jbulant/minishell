/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:26:22 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/23 03:03:24 by jbulant          ###   ########.fr       */
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
# include "ft_error.h"
# include "get_next_line.h"

typedef enum e_ms_status
{
	INTERPRET = 0,
	TERMINATE = 1
}			t_ms_status;

typedef struct	s_argbuffer
{
	char	buffer[_POSIX_ARG_MAX];
	size_t	total_size;
	char	**keys;
}				t_argbuffer;

typedef struct	s_minishell
{
	t_list		*env;
	t_ms_status	status;
	int			(*action)(struct s_minishell *);
	int			(*builtin[MAX_BUILTINS])();
}				t_minishell;

int				msh_init(char **env, t_minishell *msh);
int				get_usr_input(t_minishell *msh);
int				parse_input(char *input, t_minishell *msh);

#endif
