/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 07:50:20 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/25 01:09:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "msh_builtin.h"

t_bool	isvalidkey(char *key)
{
	t_char_pattern	cp;
	char			*eq;
	size_t			i;
	size_t			len;

	if (!(eq = ft_strchr(key, '='))
		|| eq == key
		|| ft_strchr(++eq, '=')
		|| !(len = (eq - 1) - key))
		return (FALSE);
	cp = create_char_pattern("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ_");
	i = 0;
	while (i < len)
		if (!char_match_pattern(key[i++], &cp))
			return (FALSE);
	return (TRUE);
}

int		replace_elem(t_list *lst, char *value)
{
	free(lst->content);
	if (!(lst->content = ft_strdup(value)))
		return (-1);
	lst->content_size = ft_strlen(value);
	return (0);
}

t_list	*search_elem(t_list *env, char *key)
{
	size_t		klen;
	size_t		len;

	klen = ft_strchr(key, '=') - key;
	while (env)
	{
		len = (void*)ft_strchr((char*)env->content, '=') - env->content;
		if (len == klen && !ft_strncmp(key, (char*)env->content, len))
			break ;
		env = env->next;
	}
	return (env);
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
