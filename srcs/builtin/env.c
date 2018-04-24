/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:29:19 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/25 00:14:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_lstprint(t_list *lst)
{
	write(1, (char*)lst->content, lst->content_size);
}

void			ft_lstprintendl(t_list *lst)
{
	if (!lst->content)
		return ;
	ft_lstprint(lst);
	ft_putchar('\n');
}

int				print_env(t_list *env)
{
	if (!env)
		return (0);
	if (env->next)
		print_env(env->next);
	ft_lstprintendl(env);
	return (0);
}

int				builtin_env(t_minishell *msh)
{
	return (print_env(msh->env));
}
