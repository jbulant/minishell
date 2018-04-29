/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 02:42:54 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/29 22:27:52 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_cderror(t_error_state err, char *filename)
{
	ft_putstr_fd(CD_H, 2);
	ft_putstr_fd(filename, 2);
	return (ft_perror(err));
}

int			set_oldpwd(t_minishell *msh, char *path)
{
	t_env_elem	elem;

	env_create_tmpkey(&elem, "OLDPWD", path);
	if (!env_find_replace(msh->env, &elem))
		ft_lstadd(&msh->env, ft_lstnew(&elem, sizeof(t_env_elem)));
	return (0);
}

int			set_pwd(t_minishell *msh, char *path)
{
	t_env_elem	elem;

	env_create_tmpkey(&elem, "PWD", path);
	if (!env_find_replace(msh->env, &elem))
		ft_lstadd(&msh->env, ft_lstnew(&elem, sizeof(t_env_elem)));
	return (0);
}

int			goto_fname(t_minishell *msh, char *path)
{
	struct stat		info;
	char		oldpwd[4096 + 1];
	char		*dummy;

	dummy = getcwd(oldpwd, 4096);
	if (lstat(path, &info) == -1)
		return (ft_cderror(CD_DNEXIST, path));
	if (!S_ISDIR(info.st_mode))
		return (ft_cderror(CD_NDIR, path));
	if (chdir(path) == -1)
		return (ft_cderror(CD_PERM, path));
	set_oldpwd(msh, dummy);
	dummy = getcwd(oldpwd, 4096);
	return (set_pwd(msh, dummy));
}

int			goto_oldpwd(t_minishell *msh)
{
	t_list		*oldpwd;
	t_env_elem	*elem;

	if (!(oldpwd = search_elem(msh->env, "OLDPWD")))
		return (-1);
	elem = ENV_ELEM(oldpwd);
	return (!goto_fname(msh, elem->content + (elem->nlen + 1)));
}

int			goto_home(t_minishell *msh)
{
	t_list		*home;
	t_env_elem	*elem;

	if (!(home = search_elem(msh->env, "HOME")))
		return (goto_fname(msh, "/"));
	elem = ENV_ELEM(home);
	return (!goto_fname(msh, elem->content + (elem->nlen + 1)));
}

int			ft_cd(t_minishell *msh)
{
	char	*file;

	file = msh->current_arg->keys[1];
	if (!file || !*file)
		return (goto_home(msh));
	else if (!ft_strcmp(file, "-"))
		return (goto_oldpwd(msh));
	return (goto_fname(msh, file));
}
