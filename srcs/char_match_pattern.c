/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_match_pattern.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 03:56:23 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 04:45:44 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pmatch.h"

t_bool			char_match_pattern(char c, t_char_pattern *cp)
{
	if (c < 0 || !(cp->pattern[c / 32] & (1 << (c % 32))))
		return (FALSE);
	return (TRUE);
}
