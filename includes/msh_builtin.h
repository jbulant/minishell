/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:35:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 19:26:14 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_BUILTIN_H
# define MSH_BUILTIN_H

# include <limits.h>
# include "libft.h"

typedef struct s_minishell	t_minishell;
typedef struct s_builtin	t_builtin;

# define BI_MAX_NAME	255

# define BI_NAMES		BI_1, BI_2, BI_3, BI_4, BI_5, BI_6
# define BI_FUNCT		BIF_1, BIF_2, BIF_3, BIF_4, BIF_5, BIF_6

# define BI_6			"cd"
# define BIF_6			ft_cd

# define BI_5			"echo"
# define BIF_5			ft_echo

# define BI_4			"unsetenv"
# define BIF_4			ft_unsetenv

# define BI_3			"setenv"
# define BIF_3			ft_setenv

# define BI_2			"exit"
# define BIF_2			sh_exit

# define BI_1			"env"
# define BIF_1			builtin_env

struct		s_builtin
{
	char	name[BI_MAX_NAME + 1];
	size_t	nlen;
	int		(*action)(t_minishell *);
};

t_builtin	*create_builtins(void);

t_bool		isvalidkey(char *key);

#endif
