/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 00:13:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 04:53:37 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*create_env_lst(char **env)
{
	t_list		*elst;
	t_list		*newlst;
	int			i;

	elst = NULL;
	i = -1;
	while (env[++i])
	{
		if (!(newlst = ft_lstnew(NULL, 0))
		|| !(newlst->content = (void*)new_env_elem(env[i])))
			return (NULL);
		newlst->content_size = sizeof(t_env_elem);
		ft_lstadd(&elst, newlst);
	}
	return (elst);
}

void			update_path(t_minishell *msh)
{
	char		*path;

	ft_arstrdel(msh->path);
	path = get_elem_value(get_env_elem(msh->env, "PATH", 4));
	if (!(msh->path = ft_strsplit(path, ':')))
	{
		msh->status = TERMINATE;
		return ((void)ft_perror(FTE_TOOBIG));
	}
}

char			*update_ps(char *psvar)
{
	static char		ps[4099];
	char			*dummy;

	if (psvar == PS_DEFAULT)
	{
		if (!(dummy = getcwd(ps, 4096)))
			*(int*)ps = *(int*)"$> ";
		else
			ft_strcat(ps, "$ ");
	}
	else
		ft_strcpy(ps, psvar);
	return (ps);
}

int				msh_init(char **env, t_minishell *msh)
{
	msh->virtual_env = NULL;
	msh->path = NULL;
	msh->env = *env ? create_env_lst(env) : NULL;
	msh->action = get_usr_input;
	msh->builtins = create_builtins();
	if (*env)
		update_path(msh);
	return (0);
}
