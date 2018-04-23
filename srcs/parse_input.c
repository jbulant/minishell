/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:03:46 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/23 03:08:54 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			parse_input(char *input, t_minishell *msh)
{
	size_t	size;

	if (!input)
		return (0);
	if ((size = ft_strlen(input)) > _POSIX_ARG_MAX)
		return (ft_perror(ARG_MAX_SIZE));
	if (ft_strequ(input, "exit"))
		msh->status = TERMINATE;
	if (check_builtins(input, msh))
		return (0);
	return (0);
}
