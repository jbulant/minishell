/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 05:25:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 07:53:02 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "msh_builtin.h"

int				ft_setenv(t_minishell *msh)
{
	t_argbuffer *arg;
	t_list		*var;
	int			i;

	if (!(arg = msh->current_arg) || !arg->keys[0])
		return (0);
	i = 0;
	while (arg->keys[++i])
	{
		if (!isvalidkey(arg->keys[i]))
			continue ;
		if (!(var = search_elem(msh->env, arg->keys[i])))
		{
			if (!(var = ft_lstnew(arg->keys[i], ft_strlen(arg->keys[i]) + 1)))
				return (-1);
			ft_lstadd(&msh->env, var);
		}
		else if (replace_elem(var, arg->keys[i]) == -1)
			return (-1);
	}
	return (0);
}
