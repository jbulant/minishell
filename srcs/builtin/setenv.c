/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 05:25:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/02 02:08:16 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			env_find_replace(t_list *env, t_env_elem *elem)
{
	while (env)
	{
		if (env_elem_cmp(elem, ENV_ELEM(env)))
		{
			env_elem_update(ENV_ELEM(env), elem->content);
			return (1);
		}
		env = env->next;
	}
	return (0);
}

int			ft_setenv(t_minishell *msh)
{
	t_env_elem		elem;
	t_argbuffer		*current_arg;
	char			*key;
	int				i;

	current_arg = msh->current_arg;
	i = -1;
	while ((key = current_arg->keys[++i]))
	{
		if (!ft_strchr(key, '=') || *key == '=')
			continue ;
		env_elem_update(&elem, key);
		if (!env_find_replace(msh->env, &elem))
			ft_lstadd(&msh->env, ft_lstnew(&elem, sizeof(t_env_elem)));
		if (elem.nlen == 4 && !ft_strncmp(elem.content, "PATH", 4))
			update_path(msh, msh->env);
	}
	return (0);
}
