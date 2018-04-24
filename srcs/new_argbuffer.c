/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argbuffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 01:40:00 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 06:12:42 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			del_argbuffer(t_argbuffer **argbuffer)
{
	if (!*argbuffer)
		return ;
	free((*argbuffer)->keys);
	free(*argbuffer);
	*argbuffer = NULL;
}

t_argbuffer		*new_argbuffer(char *str)
{
	t_argbuffer *ret;

	if (!str || !(ret = (t_argbuffer*)malloc(sizeof(t_argbuffer))))
		return (NULL);
	ft_strcpy(ret->buffer, str);
	ret->total_size = ft_strlen(ret->buffer);
	ret->keys = ft_create_wordtab(str);
	return (ret);
}
