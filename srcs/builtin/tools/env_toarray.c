/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_toarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:38:08 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/01 00:15:07 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_lstheight(t_list *head)
{
	size_t	cnt;

	cnt = 0;
	while (head)
	{
		cnt++;
		head = head->next;
	}
	return (cnt);
}

char			**env_toarray(t_list *env)
{
	char	**ar;
	size_t	height;

	height = get_lstheight(env);
	if (!(ar = ft_arstrnew(height)))
		return (NULL);
	while (env)
	{
		ar[--height] = ft_strdup(ENV_ELEM(env)->content);
		env = env->next;
	}
	return (ar);
}
