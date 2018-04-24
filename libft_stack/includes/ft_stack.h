/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:22:07 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 01:44:06 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>
# include "libft.h"

/*
**			FT_STACK : a simple stack auto-growing/resizing.
**						[LIBFT MODULE]
**
**	return values for (int(*function)()) :
**		0 == ERROR
**		1 == OK
**
**	can be checked like 'if (ft_stack_add_content(foo)) then SUCCESS'
**
**	ft_stack_init() MUST be called at first before adding content
**	the t_stack given in parameter need to be allocated by your preference.
*/

# define FT_STACK_ERROR			0
# define FT_STACK_SUCCESS		1
# define FT_STACK_EMPTY			0

# define MAX_STACK_BLOCK_SIZE   256
# define INITIAL_STACK_SIZE     10

typedef struct	s_stack_block
{
	size_t	size;
	void	**content;
}				t_stack_block;

typedef struct	s_stack
{
	t_stack_block	**blocks;
	size_t			blocks_count;
	size_t			max_height;
	size_t			chunk_size;
}				t_stack;

int				ft_stack_init(t_stack *stack, size_t chunk_size);
int				ft_stack_add_content(t_stack *stack, void *content);
void			*ft_stack_get_content(t_stack *stack);

int				ft_stack_newblock(t_stack *stack);
int				ft_stack_realloc(t_stack *stack);

size_t			ft_stack_totalsize(t_stack *stack);

#endif
