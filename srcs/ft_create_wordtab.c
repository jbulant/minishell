/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_wordtab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 04:05:30 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 04:46:13 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pmatch.h"
#include "libft.h"

static size_t	get_wc(char *str, t_char_pattern delim)
{
	size_t	wc;

	wc = 0;
	while (*str)
	{
		while (char_match_pattern(*str, &delim))
			str++;
		if (!*str)
			break ;
		wc++;
		while (*str && !char_match_pattern(*str, &delim))
			str++;
	}
	return (wc);
}

char			**ft_create_wordtab(char *str)
{
	char			**ret;
	t_char_pattern	delim;
	size_t			wc;
	size_t			i;

	if (!str)
		return (NULL);
	delim = create_char_pattern("\t\v\n\f\r ");
	wc = get_wc(str, delim);
	if (!(ret = ft_arstrnew(wc)))
		return (NULL);
	i = 0;
	while (i < wc)
	{
		while (char_match_pattern(*str, &delim))
			str++;
		ret[i++] = str;
		while (*str && !char_match_pattern(*str, &delim))
			str++;
		if (*str)
			*str++ = '\0';
	}
	return (ret);
}
