/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 00:13:40 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 06:28:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			msh_init(char **env, t_minishell *msh)
{
	ft_bzero(msh, sizeof(msh));
	msh->env = ft_lstfromarray(env);
	msh->action = get_usr_input;
	msh->builtins = create_builtins();
	return (0);
}
