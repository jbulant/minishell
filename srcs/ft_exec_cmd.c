/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 05:40:17 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/28 20:20:53 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void restore_env(t_minishell *msh, t_list *to_restore, void *old_cntt)
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

char	**new_virtual_env(t_minishell *msh)
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

int		ft_launch(t_minishell *msh, char *path)
{
	pid_t	pid;

	if ((!msh->virtual_env
 	&& !(msh->virtual_env = new_virtual_env(msh)))
	|| (pid = fork()) < 0)
		return (0);
	if (pid == 0)
		execve(path, msh->current_arg->keys, msh->virtual_env);
	else
	{
		wait(&pid);
		ft_arstrdel(msh->virtual_env);
		msh->virtual_env = NULL;
	}
	return (1);
}

int		ft_exec_cmd(t_minishell *msh)
{
	char	filepath[4096];
	size_t	plen;
	int		i;

	if (access(msh->current_arg->keys[0], X_OK) == 0)
		return (ft_launch(msh, msh->current_arg->keys[0]));
	if (!msh->path)
		return (0);
	i = -1;
	while (msh->path[++i])
	{
		ft_strcpy(filepath, msh->path[i]);
		plen = ft_strlen(filepath);
		if (plen && filepath[plen - 1] != '/')
			ft_strcpy(filepath + plen++, "/");
		ft_strcpy(filepath + plen, msh->current_arg->keys[0]);
		if (access(filepath, X_OK) == 0)
			return (ft_launch(msh, filepath));
	}
	return (0);
}
