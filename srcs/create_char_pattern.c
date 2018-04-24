/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_char_pattern.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 03:54:56 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 05:24:01 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pmatch.h"
#include <stdio.h>
t_char_pattern	create_char_pattern(char *pattern)
{
	t_char_pattern	ret;
	int				i;
	int				j;

	ft_bzero(&ret, sizeof(ret));
	while (*pattern)
	{
		if (*pattern < 0)
			continue ;
		i = *pattern % 32;
		j = *pattern / 32;
		if (!(ret.pattern[j] & (1 << i)))
			ret.pattern[j] |= (1 << i);
		pattern++;
	}
	return (ret);
}
