/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 02:34:44 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 20:18:42 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			goto_fname(t_minishell *msh, char *path)
{
	struct stat	info;
	char		oldpwd[_POSIX_ARG_MAX + 1];
	char		*dummy;

	dummy = getcwd(oldpwd, _POSIX_ARG_MAX);
	if (lstat(path, &info) == -1)
		return (ft_cderror(FTE_NOENT, path));
	if (!S_ISDIR(info.st_mode))
		return (ft_cderror(FTE_NOTDIR, path));
	if (chdir(path) == -1)
		return (ft_cderror(FTE_ACCES, path));
	env_setvar(msh, "OLDPWD", dummy);
	dummy = getcwd(oldpwd, 4096);
	return (env_setvar(msh, "PWD", dummy));
}

int			env_gotovar(t_minishell *msh, char *var)
{
	t_list		*lst;
	t_env_elem	*elem;

	if (!(lst = search_elem(msh->env, var)))
		return (goto_fname(msh, "/"));
	elem = ENV_ELEM(lst);
	if (ft_strequ(var, "OLDPWD"))
		ft_putendl(elem->content + (elem->nlen + 1));
	return (!goto_fname(msh, elem->content + (elem->nlen + 1)));
}
