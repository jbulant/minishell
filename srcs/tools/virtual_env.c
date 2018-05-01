/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 02:43:08 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 20:20:06 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	restore_env(t_minishell *msh, t_list *to_restore, void *old_cntt)
{
	if (!to_restore)
	{
		to_restore = msh->env->next;
		free(msh->env->content);
		free(msh->env);
		msh->env = to_restore;
	}
	else
		to_restore->content = old_cntt;
}

char		**new_virtual_env(t_minishell *msh)
{
	char		**ret;
	t_list		*to_restore;
	void		*old_cntt;
	t_env_elem	elem;

	env_create_tmpkey(&elem, "_", msh->current_arg->keys[0]);
	if (!(to_restore = search_elem(msh->env, "_")))
		ft_lstadd(&msh->env, ft_lstnew(&elem, sizeof(t_env_elem)));
	old_cntt = !to_restore ? NULL : to_restore->content;
	if (old_cntt)
		to_restore->content = (void*)&elem;
	ret = env_toarray(msh->env);
	restore_env(msh, to_restore, old_cntt);
	return (ret);
}
