/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 07:03:00 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/02 00:50:50 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*str_is_var(char *str, t_list *env)
{
	t_list	*found;

	if (!str || *str != '$'
	|| !(found = search_elem(env, str + 1)))
		return (NULL);
	return (get_elem_value(ENV_ELEM(found)));
}

int				ft_echo(t_minishell *msh)
{
	char	*str;
	char	*var;
	int		i;

	i = 0;
	while ((str = msh->current_arg->keys[++i]))
	{
		var = str_is_var(str, msh->env);
		ft_putstr(var ? var : str);
		ft_putchar(msh->current_arg->keys[i + 1] ? ' ' : '\n');
	}
	return (0);
}
