/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_get_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:46:34 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/18 01:46:35 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	*ft_stack_get_content(t_stack *stack)
{
	t_stack_block	*block;
	void			*content;

	if (!stack->blocks_count)
		return (FT_STACK_EMPTY);
	block = stack->blocks[stack->blocks_count - 1];
	content = block->content[--block->size];
	if (!block->size)
	{
		free(block->content);
		free(block);
		stack->blocks_count--;
	}
	return (content);
}
