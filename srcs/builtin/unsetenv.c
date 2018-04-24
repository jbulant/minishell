/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 05:25:35 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 08:35:33 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "msh_builtin.h"

static void find_and_delete(t_list **head, char *str)
{
	size_t		klen;
	int			found;
	t_list		*lst[2];

	klen = ft_strchr(str, '=') - str;
	found = -1;
 	lst[1] = *head;
	lst[0] = NULL;
	while (lst[1])
	{
		if (!(found = ft_strncmp((char*)(lst[1])->content, str, klen)))
			break ;
		lst[0] = lst[1];
		lst[1] = lst[1]->next;
	}
	if (found)
		return ;
	if (lst[0])
		lst[0]->next = lst[1]->next;
	else
		*head = lst[1]->next;
	ft_lstdelone(&lst[1], ft_memdel);
}

int				ft_unsetenv(t_minishell *msh)
{
	t_argbuffer *arg;
	int			i;

	if (!(arg = msh->current_arg) || !arg->keys[0])
		return (0);
	i = 0;
	while (arg->keys[++i])
	{
		if (!isvalidkey(arg->keys[i]))
			continue ;
		find_and_delete(&msh->env, arg->keys[i]);
	}
	return (0);
}
