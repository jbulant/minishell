/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 05:40:17 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/02 00:50:44 by jbulant          ###   ########.fr       */
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
	{
		if (execve(path, &ARG_KEYS(msh->current_arg), msh->virtual_env) == -1)
		{
			ft_putstr_fd(ft_strerror(FTE_EXECF), 1);
			ft_putendl_fd(ARG_KEYS(msh->current_arg), 1);
			exit(1);
		}
	}
	else
	{
		wait(&pid);
		ft_arstrdel(&msh->virtual_env);
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

int				ft_exec_cmd(t_minishell *msh)
{
	char	filepath[4096];
	size_t	plen;
	int		i;

	if ((i = file_is_exec(ARG_KEYS(msh->current_arg))) != 0)
	{
		if (i > 0)
			return (ft_launch(msh, ARG_KEYS(msh->current_arg)));
		return (ft_execerror((i * -1) + 2, ARG_KEYS(msh->current_arg)));
	}
	if (!msh->path)
		return (0);
	i = -1;
	while (msh->path[++i])
	{
		ft_strcpy(filepath, msh->path[i]);
		if ((plen = ft_strlen(filepath)) && filepath[plen - 1] != '/')
			ft_strcpy(filepath + plen++, "/");
		if (access(filepath, R_OK) == -1)
			continue ;
		ft_strcpy(filepath + plen, ARG_KEYS(msh->current_arg));
		if (file_is_exec(filepath) == 1)
			return (ft_launch(msh, filepath));
	}
	return (0);
}
