/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 00:37:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/23 02:42:58 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_minishell msh;

	(void)ac;
	(void)av;
	msh_init(env, &msh);
	while(msh.status != TERMINATE)
		msh.action(&msh);
	return 0;
}
