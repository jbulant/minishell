/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pmatch.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 03:50:36 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/26 16:46:23 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PMATCH_H
# define FT_PMATCH_H

#include "libft.h"

typedef union	u_chrmsk
{
	int			pattern[4];
}				t_chrmsk;

t_chrmsk		new_chrmsk(char *pattern);
t_bool			char_match_pattern(char c, t_chrmsk *cp);

char			**ft_create_wordtab(char *str, t_chrmsk delim);

#endif
