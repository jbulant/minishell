/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 00:13:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/25 01:03:00 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*create_env_lst(char **env)
{
	t_list		*elst;
	t_list		*newlst;
	int			i;

	elst = NULL;
	i = -1;
	while (env[++i])
	{
		if (!(newlst = ft_lstnew(NULL, 0))
		|| !(newlst->content = (void*)new_env_elem(env[i])))
			return (NULL);
		newlst->content_size = sizeof(t_env_elem);
		ft_lstadd(&elst, newlst);
	}
	return (elst);
}

int			msh_init(char **env, t_minishell *msh)
{
	ft_bzero(msh, sizeof(msh));
	msh->env = create_env_lst(env);
	msh->action = get_usr_input;
	msh->builtins = create_builtins();
	return (0);
}
