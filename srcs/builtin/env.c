/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:29:19 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/23 11:44:31 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_builtin.h"

int				print_env(t_list *env)
{
	if (!env)
		return (0);
	if (env->next)
		print_env(env->next);
	ft_putendl((char*)env->content);
	return (0);
}

int				builtin_env(t_minishell *msh)
{
	return (print_env(msh->env));
}