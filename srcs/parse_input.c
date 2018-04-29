/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 01:03:46 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/27 05:47:35 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			parse_input(char *input, t_minishell *msh)
{
	int			ret;
	size_t		size;

	if (!input)
		return (0);
	if ((size = ft_strlen(input)) > _POSIX_ARG_MAX)
		return (ft_perror(ARG_MAX_SIZE));
	if (!(msh->current_arg = new_argbuffer(input)))
		return (-1);
	if ((ret = check_builtins(msh->current_arg, msh)) != -1)
		msh->builtins[ret].action(msh);
	else if (!ft_exec_cmd(msh) && msh->current_arg->keys[0])
	{
		ft_putstr_fd(E2, 2);
		ft_putendl_fd(msh->current_arg->keys[0], 2);
	}
	del_argbuffer(&msh->current_arg);
	return (0);
}
