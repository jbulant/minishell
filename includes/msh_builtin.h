/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_builtin.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:35:33 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/23 03:26:07 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_BUILTIN_H
# define MSH_BUILTIN_H

# include <limits.h>
# include "libft.h"

# define BI_MAX_NAME	255
# define BI_COUNT		1

# define BI_1			"env"
# define BIF_1			builtin_env

# define BI_NAMES		BI_1
# define BI_FUNCT		BIF_1

typedef struct	s_builtin
{
	char	name[BI_MAX_NAME + 1];
	int		(*action)();
}				t_builtin;

int				builtin_env(t_minishell *msh);

#endif
