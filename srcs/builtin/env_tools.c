/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 07:50:20 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/25 04:05:09 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "msh_builtin.h"

char			*get_elem_value(t_env_elem *elem)
{
	static char		value[4096];

	if (!elem)
		return (NULL);
	ft_strcpy(value, elem->content + (elem->nlen ? elem->nlen + 1 : 0));
	return (value);
}

char			*get_elem_key(t_env_elem *elem)
{
	static char		key[4096];

	if (!elem)
		return (NULL);
	ft_strncpy(key, elem->content, elem->nlen ? elem->nlen : elem->total_len);
	return (key);
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

t_bool			env_elem_cmp(t_env_elem *e1, t_env_elem *e2)
{
	size_t	cmp;

	if (e1->nlen && e2->nlen)
	{
		if ((cmp = e1->nlen) != e2->nlen)
			return (FALSE);
	}
	else if (e1->nlen && !e2->nlen)
	{
		if (e1->nlen != (cmp = e2->total_len))
			return (FALSE);
	}
	else if (!e1->nlen && e2->nlen)
	{
		if ((cmp = e1->total_len) != e2->nlen)
			return (FALSE);
	}
	else
		return (FALSE);
	if (ft_strncmp(e1->content, e2->content, cmp))
		return (FALSE);
	return (TRUE);
}

void			env_elem_update(t_env_elem *elem, char *content)
{
	char		*dummy;

	ft_strcpy(elem->content, content);
	if ((dummy = ft_strchr(content, '=')))
	{
		elem->nlen = dummy - content;
		elem->total_len = ft_strlen(content);
	}
	else
	{
		elem->nlen = 0;
		elem->total_len = ft_strlen(content);
	}
}

t_env_elem		*new_env_elem(char *content)
{
	t_env_elem	*elem;
	char		*dummy;

	if (!(elem = (t_env_elem*)malloc(sizeof(t_env_elem))))
		return (NULL);
	ft_strcpy(elem->content, content);
	if ((dummy = ft_strchr(content, '=')))
	{
		elem->nlen = dummy - content;
		elem->total_len = ft_strlen(content);
	}
	else
	{
		elem->nlen = 0;
		elem->total_len = ft_strlen(content);
	}
	return (elem);
}
