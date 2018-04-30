/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_match_pattern.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 03:56:23 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 04:06:31 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			char_match_pattern(char c, t_chrmsk *cp)
{
	if (c < 0 || !(cp->pattern[c / 32] & (1 << (c % 32))))
		return (FALSE);
	return (TRUE);
}
