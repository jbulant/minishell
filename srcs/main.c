/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:37:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/05/02 00:53:56 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	msh_clean(t_minishell *msh)
{
	ft_lstdel(&msh->env, ft_memdel);
	del_argbuffer(&msh->current_arg);
	ft_arstrdel(&msh->path);
}

static void	sighandler(int sig)
{
	signal(sig, SIG_IGN);
	ft_putchar('\n');
	ft_putstr(update_ps(PS_DEFAULT));
	signal(SIGINT, sighandler);
}

int			main(int ac, char **av, char **env)
{
	t_minishell msh;

	ft_bzero(&msh, sizeof(t_minishell));
	(void)ac;
	(void)av;
	signal(SIGINT, sighandler);
	msh_init(env, &msh);
	while (msh.status != TERMINATE)
		msh.action(&msh);
	msh_clean(&msh);
	return (msh.retval);
}
