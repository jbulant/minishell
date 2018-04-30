/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 02:42:54 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 04:55:28 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_cderror(t_error_state err, char *filename)
{
	ft_putstr_fd(CD_H, 2);
	ft_putstr_fd(filename, 2);
	return (ft_perror(err));
}

int			ft_cd(t_minishell *msh)
{
	char	*file;

	file = msh->current_arg->keys[1];
	if (!file || !*file)
		return (env_gotovar(msh, "HOME"));
	else if (!ft_strcmp(file, "-"))
		return (env_gotovar(msh, "OLDPWD"));
	return (goto_fname(msh, file));
}
