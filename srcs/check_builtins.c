/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:45:39 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 05:22:36 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_builtins(t_argbuffer *arg, t_minishell *msh)
{
	int		i;

	i = -1;
	while (++i < BI_COUNT)
	{
		if (ft_strequ(arg->keys[0], msh->builtins[i].name))
			return (i);
	}
	return (-1);
}
