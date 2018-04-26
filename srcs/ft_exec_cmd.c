/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 05:40:17 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/26 16:48:19 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_launch(t_minishell *msh, char *path)
{
	pid_t	pid;

	if (!msh->virtual_env
	&& !(msh->virtual_env = env_toarray(msh->env)))
		return ;
	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
		execve(path, msh->current_arg->keys, msh->virtual_env);
	wait(&pid);
	free(msh->virtual_env);
	msh->virtual_env = NULL;
}

int		ft_exec_cmd(t_minishell *msh)
{
	char	filepath[4096];
	size_t	plen;
	int		i;

	if (access(msh->current_arg->keys[0], X_OK) == 0)
	{
		ft_launch(msh, msh->current_arg->keys[0]);
		return (1);
	}
	i = -1;
	while (msh->path[++i])
	{
		ft_strcpy(filepath, msh->path[i]);
		plen = ft_strlen(filepath);
		if (plen && filepath[plen - 1] != '/')
			ft_strcpy(filepath + plen++, "/");
		ft_strcpy(filepath + plen, msh->current_arg->keys[0]);
		if (access(filepath, X_OK) == 0)
		{
			ft_launch(msh, filepath);
			return (1);
		}
	}
	return (0);
}
