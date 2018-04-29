/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 22:23:01 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/27 22:43:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msh_prompt.h"

char		*update_ps(char *psvar)
{
	static char		ps[4096];
	char			*dummy;

	if (psvar == PS_DEFAULT)
	{
		if (!(dummy = getcwd(ps, 4095)))
			*(int*)ps = *(int*)"$> ";
		else
			ft_strcat(ps, "$ ");
	}
	else
		ft_strcpy(ps, psvar);
	return (ps);
}
