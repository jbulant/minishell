/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:33:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/26 00:57:09 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "libft.h"

# define MAX_ERROR_STATE	2

# define ERROR_HEAD			"minishell: "
# define ERROR_MSGS			E1, E2

# define E3					"command not found: "
# define E2					"file doesn't exist"
# define E1					"argument list too long"

typedef enum	e_error_state
{
	ARG_MAX_SIZE = 0,
	FILE_DOESNT_EXIST = 1,
	CMD_NOT_FOUND = 2
}				t_error_state;

int				ft_perror(t_error_state err);

#endif
