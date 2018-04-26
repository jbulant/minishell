/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 07:03:00 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/26 16:38:20 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_echo(t_minishell *msh)
{
	char	*str;
	int		i;

	i = 0;
	while ((str = msh->current_arg->keys[++i]))
	{
		ft_putstr(str);
		ft_putchar(msh->current_arg->keys[i + 1] ? ' ' : '\n');
	}
	return (0);
}
