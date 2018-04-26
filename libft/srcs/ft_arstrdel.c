/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arstrdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 03:43:28 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/25 03:47:45 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void					ft_arstrdel(char **ar)
{
	int		i;

	if (!ar)
		return ;
	i = -1;
	while (ar[++i])
		free(ar[i]);
	free(ar);
}
