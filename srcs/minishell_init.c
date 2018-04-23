/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 00:13:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/23 02:44:12 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list			*ft_lstfromarray(char **ar)
{
	t_list	*head;
	t_list	*new;
	int		i;

	head = NULL;
	i = 0;
	while (ar[i])
	{
		if (!(new = ft_lstnew(ar[i], ft_strlen(ar[i]))))
			return (NULL);
		ft_lstadd(&head, new);
		i++;
	}
	return (head);
}

int			msh_init(char **env, t_minishell *msh)
{
	ft_bzero(msh, sizeof(msh));
	msh->env = ft_lstfromarray(env);
	msh->action = get_usr_input;
	return (0);
}
