/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pmatch.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 03:50:36 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 03:55:29 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PMATCH_H
# define FT_PMATCH_H

#include "libft.h"

typedef union	u_char_pattern
{
	int			pattern[4];
}				t_char_pattern;

t_char_pattern	create_char_pattern(char *pattern);
t_bool			char_match_pattern(char c, t_char_pattern *cp);

#endif
