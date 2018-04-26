/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:37:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/25 03:47:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void msh_clean(t_minishell *msh)
{
	ft_lstdel(&msh->env, ft_memdel);
	del_argbuffer(&msh->current_arg);
	ft_arstrdel(msh->path);
}

int main(int ac, char **av, char **env)
{
	t_minishell msh;

	(void)ac;
	(void)av;
	msh_init(env, &msh);
	while(msh.status != TERMINATE)
		msh.action(&msh);
	msh_clean(&msh);
	return 0;
}
