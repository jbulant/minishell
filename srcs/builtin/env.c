/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:29:19 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 06:28:42 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "msh_builtin.h"

void			ft_lstprint_content(t_list *lst)
{
	write(1, (char*)lst->content, lst->content_size);
}

void			ft_lstprintendl_content(t_list *lst)
{
	if (!lst->content)
		return ;
	ft_lstprint_content(lst);
	ft_putchar('\n');
}

int				print_env(t_list *env)
{
	if (!env)
		return (0);
	if (env->next)
		print_env(env->next);
	ft_lstprintendl_content(env);
	return (0);
}

int				builtin_env(t_minishell *msh)
{
	return (print_env(msh->env));
}
