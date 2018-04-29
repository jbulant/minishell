/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getusr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 00:53:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/28 20:09:06 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			get_usr_input(t_minishell *msh)
{
	char	**tab;
	char	*input;
	int		ret;
	int		i;

	ret = 0;
	input = NULL;
	ft_putstr(update_ps(PS_DEFAULT));
	if (get_next_line(0, &input) <= 0 || !input)
		return (-1);
	tab = *input ? ft_strsplit(input, ';') : NULL;
	free(input);
	if (!tab)
		return (0);
	i = -1;
	while (tab[++i])
	{
		if ((ret = parse_input(tab[i], msh)) == -1)
			break ;
	}
	ft_arstrdel(tab);
	return (ret);
}
