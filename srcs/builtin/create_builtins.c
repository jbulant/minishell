/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_builtins.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 03:25:39 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 03:47:55 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "msh_builtin.h"

static char		*builtin_n(int i)
{
	char	*name[BI_COUNT] = {BI_NAMES};

	return (name[i]);
}

static int		(*builtin_f(int i))()
{
	int			(*action[BI_COUNT])() = {BI_FUNCT};

	return (action[i]);
}

t_builtin		*create_builtins(void)
{
	static t_builtin	builtins[BI_COUNT];
	int					i;

	i = -1;
	while (++i < BI_COUNT)
	{
		ft_strcpy(builtins[i].name, builtin_n(i));
		builtins[i].nlen = ft_strlen(builtins[i].name);
		builtins[i].action = builtin_f(i);
	}
	return (builtins);
}
