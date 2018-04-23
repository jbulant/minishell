/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:30:24 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/23 01:57:36 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

const char	*ston_errormsg(t_error_state err)
{
	const char	*msg[MAX_ERROR_STATE] = {ERROR_MSGS};

	if (err < 0 || err > MAX_ERROR_STATE)
		return (NULL);
	return (msg[err]);
}

int			ft_perror(t_error_state err)
{
	const char	*msg;

	if ((msg = ston_errormsg(err)))
		ft_putendl_fd((char*)msg, 2);
	return (-1);
}
