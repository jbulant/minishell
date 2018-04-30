/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 04:43:46 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 04:46:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char			*get_elem_value(t_env_elem *elem)
{
	static char		value[4096];

	if (!elem)
		return (NULL);
	ft_strcpy(value, elem->content + (elem->nlen ? elem->nlen + 1 : 0));
	return (value);
}

int				env_setvar(t_minishell *msh, char *var, char *value)
{
	t_env_elem	elem;

	env_create_tmpkey(&elem, var, value);
	if (!env_find_replace(msh->env, &elem))
		ft_lstadd(&msh->env, ft_lstnew(&elem, sizeof(t_env_elem)));
	return (0);
}

t_env_elem		*get_env_elem(t_list *env, char *name, size_t nlen)
{
	while (env)
	{
		if ((nlen == ENV_ELEM(env)->nlen
		|| (!ENV_ELEM(env)->nlen && nlen == ENV_ELEM(env)->total_len))
		&& !ft_strncmp(name, ENV_ELEM(env)->content, nlen))
			return (ENV_ELEM(env));
		env = env->next;
	}
	return (NULL);
}

t_list			*search_elem(t_list *env, char *key)
{
	size_t		klen;
	t_env_elem	*elem;

	if (!key)
		return (NULL);
	klen = ft_strlen(key);
	while (env)
	{
		elem = ENV_ELEM(env);
		if (klen == elem->nlen && !ft_strncmp(elem->content, key, klen))
			return (env);
		env = env->next;
	}
	return (NULL);
}
