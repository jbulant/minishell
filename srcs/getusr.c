/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getusr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 00:53:32 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/23 01:32:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			get_usr_input(t_minishell *msh)
{
	char	*input;
	int		ret;

	ft_putstr("$> ");
	if (!get_next_line(0, &input))
		return (-1);
	ret = parse_input(input, msh);
	free(input);
	return (ret);
}
