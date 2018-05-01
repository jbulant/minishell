/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 05:25:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/01 01:53:22 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_and_delete(t_list **env, t_env_elem *elem)
{
	t_list	*lst;
	t_list	*prev;

	prev = NULL;
	lst = *env;
	while (lst)
	{
		if (env_elem_cmp(elem, ENV_ELEM(lst)))
		{
			if (prev)
				prev->next = lst->next;
			else
				*env = lst->next;
			ft_lstdelone(&lst, ft_memdel);
			return (1);
		}
		prev = lst;
		lst = lst->next;
	}
	return (0);
}

int			ft_unsetenv(t_minishell *msh)
{
	t_env_elem		elem;
	char			*key;
	int				i;

	i = -1;
	while ((key = msh->current_arg->keys[++i]))
	{
		env_elem_update(&elem, key);
		if (find_and_delete(&msh->env, &elem)
		&& elem.nlen == 4 && !ft_strncmp(elem.content, "PATH", 4))
			update_path(msh, msh->env);
	}
	return (0);
}
