/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 03:45:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 04:52:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				sh_exit(t_minishell *msh)
{
	msh->status = TERMINATE;
	if (msh->current_arg->keys[1])
		msh->retval = ft_atoi(msh->current_arg->keys[1]);
	return (0);
}
