/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:33:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/27 03:55:39 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "libft.h"

# define MAX_ERROR_STATE	5

# define DFLT_H				"minishell: "
# define CD_H				DFLT_H "cd: '"
# define ERROR_MSGS			E1, E2, E3, E4, E5

# define E5					"' file is not a directory"
# define E4					"' file doesn't exist"
# define E3					"' permission denied"
# define E2					DFLT_H "command not found: "
# define E1					DFLT_H "argument list too long"

typedef enum	e_error_state
{
	ARG_MAX_SIZE = 0,
	CMD_NOT_FOUND = 1,
	CD_PERM = 2,
	CD_DNEXIST = 3,
	CD_NDIR = 4
}				t_error_state;

int				ft_cderror(t_error_state err, char *filename);
int				ft_perror(t_error_state err);

#endif
