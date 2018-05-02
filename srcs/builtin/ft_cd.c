/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 02:42:54 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/02 00:50:47 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*parse_filename(char *buffer, char *file, t_list *env)
{
	t_list		*home;
	size_t		len;

	if (!file || !*file)
		return (NULL);
	if (*file == '~' && (home = search_elem(env, "HOME")))
	{
		ft_strcpy(buffer, get_elem_value(ENV_ELEM(home)));
		len = ft_strlen(buffer);
		if (buffer[len - 1] != '/' && *(file + 1) != '/')
			*(short*)(buffer + len) = *(short*)"/";
		file++;
	}
	ft_strcat(buffer, file);
	return (buffer);
}

int			ft_cderror(t_error_state err, char *filename)
{
	ft_putstr_fd(CD_H, 2);
	ft_putstr_fd(filename, 2);
	return (ft_perror(err));
}

int			ft_cd(t_minishell *msh)
{
	char	fname[_POSIX_ARG_MAX + 1];
	char	*file;

	*(long*)fname = 0;
	file = parse_filename(fname, msh->current_arg->keys[1], msh->env);
	if (!file || !*file)
		return (env_gotovar(msh, "HOME"));
	else if (!ft_strcmp(file, "-"))
		return (env_gotovar(msh, "OLDPWD"));
	return (goto_fname(msh, file));
}
