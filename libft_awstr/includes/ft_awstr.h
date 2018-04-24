/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_awstr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 02:00:52 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/24 01:18:06 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AWSTR_H
# define FT_AWSTR_H

# include <unistd.h>
# include "libft.h"

/*
**				AWSTR stands for Auto-Write STRings
**						[LIBFT MODULE]
**
**	The size of your awstr MUST BE set to 0, no matter the buffer content.
** 	else, the result will be undefined behavior.
**
**	UTILITY:
**	Every function writing into buffer will automatically write it if its
**	max length is reached.
**
**	FUNCTIONS:
**	--ft_putawstr(t_awstr *str):
**		Write the entire awstr and 'clear' it.
**	--ft_awstrset(t_awstr *dst, char c, size_t n):
**		Set 'n' characters 'c' following the buffer of 'dst'
**	--ft_awstrncat(t_awstr *dst, const char *src,):
**		Concatenate the given 'src' to the buffer of 'dst'
**	--ft_awstrlpad(t_awstr *dst, const char *src, size_t n, t_awpad pad):
**		Pad to the left with given ft_awpad parameter then use awstrncat.
**		If pad's height is shorter than n, only awstrncat will be called.
**		exemple:
**			ft_awstrpad(dst, "foobar", 3, ft_awpad('-', 5));
**			ft_awputstr(dst);
**		$> --foo
**	--ft_awstrrpad(t_awstr *dst, const char *src, size_t n, t_awpad pad):
**		Use awstrncat then pad to the right with given ft_awpad parameter.
**		exemple:
**			ft_awstrrpad(dst, "foobar", 2, ft_awpad('-', 5));
**			ft_awputstr(dst);
**		$> fo---
**
**	RETURN VALUE:
**		If an error occure, the return value will be -1.
**		Else, the return value will give the amount of characters written during
**		operations.
*/

# define STR_BUFFSIZE 512

typedef struct	s_awpad
{
	char	c;
	size_t	height;
}				t_awpad;

typedef struct	s_awstr
{
	char	buffer[STR_BUFFSIZE];
	size_t	size;
	int		fd;
}				t_awstr;

t_awpad			ft_awpad(char c, size_t height);

int				ft_putawstr(t_awstr *str);

int				ft_awstrset(t_awstr *dst, char c, size_t n);

int				ft_awstrncat(t_awstr *dst, const char *src, size_t n);
int				ft_awstrncatendl(t_awstr *dst, const char *src, size_t n);

int				ft_awstrlpad(t_awstr *dst, const char *src
							, size_t n, t_awpad pad);
int				ft_awstrrpad(t_awstr *dst, const char *src
							, size_t n, t_awpad pad);

int				ft_awstrinit(t_awstr *awstr);
int				ft_setawstrfd(t_awstr *awstr, int fd);

#endif
