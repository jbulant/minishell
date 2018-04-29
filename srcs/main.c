/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:37:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/29 19:56:38 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int		g_sigint = 0;

void msh_clean(t_minishell *msh)
{
	ft_lstdel(&msh->env, ft_memdel);
	del_argbuffer(&msh->current_arg);
	ft_arstrdel(msh->path);
	// ft_arstrdel(msh->virtual_env);
}

int	redirect_eof(void)
{
	struct termios old_termios;
	struct termios new_termios;

	tcgetattr(0,&old_termios);
	new_termios             = old_termios;
	new_termios.c_cc[VEOF]  = 3;
	tcsetattr(0,TCSANOW,&new_termios);
	return (0);
}

void sighandler(int sig)
{
	signal(sig, SIG_IGN);
	redirect_eof();
	ft_putchar('\n');
	ft_putstr(update_ps(PS_DEFAULT));
	signal( SIGINT, sighandler );
}

int main(int ac, char **av, char **env)
{
	t_minishell msh;

	ft_bzero(&msh, sizeof(t_minishell));
	(void)ac;
	(void)av;
	signal( SIGINT, sighandler );
	msh_init(env, &msh);
	while(msh.status != TERMINATE)
	{
		msh.action(&msh);
		// if (g_sigint == 1)
		// 	g_sigint = 0;
	}
	msh_clean(&msh);
	return (msh.retval);
}
