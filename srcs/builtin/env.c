/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 02:29:19 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/02 00:50:56 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		print_env(t_list *env)
{
	if (!env)
		return (0);
	if (env->next)
		print_env(env->next);
	ft_putendl(ENV_ELEM(env)->content);
	ft_lstdelone(&env, ft_memdel);
	return (0);
}

static int		parse_args(t_minishell *msh, t_list **tmpenv, int i)
{
	msh->current_arg->offset = i;
	msh->virtual_env = *tmpenv ? env_toarray(*tmpenv) : ft_arstrnew(0);
	ft_lstdel(tmpenv, ft_memdel);
	if (ft_exec_cmd(msh) == 0)
	{
		ft_putstr_fd(E2, 2);
		ft_putendl_fd(msh->current_arg->keys[i], 2);
	}
	ft_arstrdel(&msh->virtual_env);
	return (0);
}

static int		check_args(t_minishell *msh, t_list **tmpenv, int i)
{
	t_env_elem	elem;
	char		*tmp;

	while ((tmp = msh->current_arg->keys[++i]) && ft_strchr(tmp, '='))
	{
		env_elem_update(&elem, tmp);
		if (!env_find_replace(*tmpenv, &elem))
			ft_lstadd(&(*tmpenv), ft_lstnew(&elem, sizeof(t_env_elem)));
		if (elem.nlen == 4 && !ft_strncmp(elem.content, "PATH", 4))
			update_path(msh, *tmpenv);
	}
	return (tmp ? i : 0);
}

int				builtin_env(t_minishell *msh)
{
	t_list	*tmpenv;
	char	**path;
	int		i;

	path = msh->path;
	i = 0;
	if (msh->current_arg->keys[1]
		&& !ft_strcmp(msh->current_arg->keys[1], "-i"))
	{
		tmpenv = NULL;
		i = 1;
	}
	else
		tmpenv = ft_lstdup(msh->env);
	if ((i = check_args(msh, &tmpenv, i)))
		parse_args(msh, &tmpenv, i);
	else
		print_env(tmpenv);
	update_path(msh, msh->env);
	return (0);
}
