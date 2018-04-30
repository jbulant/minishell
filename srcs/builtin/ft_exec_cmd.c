/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 05:40:17 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 04:27:53 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_execerror(t_error_state err, char *filename)
{
	ft_putstr_fd(DFLT_H, 2);
	ft_putstr_fd(filename, 2);
	return (ft_perror(err));
}

static int		ft_launch(t_minishell *msh, char *path)
{
	pid_t	pid;

	if ((!msh->virtual_env && !(msh->virtual_env = new_virtual_env(msh)))
		|| (pid = fork()) < 0)
	{
		msh->status = TERMINATE;
		ft_perror(FTE_NOMEM);
		return (0);
	}
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

static int		file_is_exec(char *path)
{
	struct stat		info;
	int				ret;

	if (lstat(path, &info) == -1)
		ret = 0;
	else if (S_ISDIR(info.st_mode))
		ret = -1;
	else if (access(path, X_OK) != 0)
		ret = -2;
	else
		ret = 1;
	return (ret);
}

int		ft_exec_cmd(t_minishell *msh)
{
	char	filepath[4096];
	size_t	plen;
	int		i;

	if ((i = file_is_exec(msh->current_arg->keys[0])) != 0)
		return (i > 0 ? ft_launch(msh, msh->current_arg->keys[0])
					: ft_execerror((i * -1) + 2, msh->current_arg->keys[0]));
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
		if (file_is_exec(filepath) == 1)
			return (ft_launch(msh, filepath));
	}
	return (0);
}