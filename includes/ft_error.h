/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:33:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/02 00:41:05 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "libft.h"

# define MAX_ERROR_STATE	8

# define DFLT_H				"minishell: "
# define CD_H				DFLT_H "cd: "
# define ERROR_MSGS			E1, E2, E3, E4, E5, E6, E7, E8

# define E8					DFLT_H "exec format error: "
# define E7					"Out of memory"
# define E6					": Not a directory"
# define E5					": Permission denied"
# define E4					": Is a directory"
# define E3					": No such file or directory"
# define E2					DFLT_H "command not found: "
# define E1					DFLT_H "argument list too long"

typedef enum	e_error_state
{
	FTE_TOOBIG = 0,
	FTE_NOCMD = 1,
	FTE_NOENT = 2,
	FTE_ISDIR = 3,
	FTE_ACCES = 4,
	FTE_NOTDIR = 5,
	FTE_NOMEM = 6,
	FTE_EXECF = 7
}				t_error_state;

int				ft_cderror(t_error_state err, char *filename);
char			*ft_strerror(t_error_state err);
int				ft_perror(t_error_state err);

#endif
