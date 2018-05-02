/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:30:24 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/02 00:50:48 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

char		*ft_strerror(t_error_state err)
{
	static char	*msg[MAX_ERROR_STATE] = {ERROR_MSGS};

	if ((int)err >= MAX_ERROR_STATE)
		return (NULL);
	return (msg[err]);
}

int			ft_perror(t_error_state err)
{
	char	*msg;

	if ((msg = ft_strerror(err)))
		ft_putendl_fd(msg, 2);
	return (-1);
}
