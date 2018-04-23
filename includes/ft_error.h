/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:33:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/23 01:56:56 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "libft.h"

# define MAX_ERROR_STATE	1

# define ERROR_HEAD			"minishell: "

# define E1					"command-line size too big."
# define ERROR_MSGS			E1

typedef enum	e_error_state
{
	ARG_MAX_SIZE = 0
}				t_error_state;

int				ft_perror(t_error_state err);

#endif
