/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:11:45 by jbulant           #+#    #+#             */
/*   Updated: 2018/04/30 22:57:25 by jbulant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef unsigned char	t_byte;
typedef enum e_bool		t_bool;

enum		e_bool
{
	FALSE = 0,
	TRUE = 1
};

/*
**	INDEXES:
**		_FT_LST_
**		_FT_STR_
**		_FT_MEM_
**		_FT_PMATCH_
**		_FT_CONVERT_
**		_FT_PUT_
**		_FT_IS_
**		_FT_MATH_
*/

/*
**	_FT_LST_				FUNCTIONS
*/

typedef struct s_list	t_list;

struct			s_list
{
	t_list	*next;
	void	*content;
	size_t	content_size;
};

t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void **));
void			ft_lstdel(t_list **alst, void (*del)(void **));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstappend(t_list **alst, t_list *new);
void			ft_lstjoin(t_list **alst, t_list *new);
void			ft_lstsort(t_list **head, int (*cmp)());
void			ft_lstprint(t_list *lst);
void			ft_lstrprint(t_list *lst);
void			ft_lstprint_content(t_list *lst);
t_list			*ft_lstfromarray(char **ar);
t_list			*ft_lstdup(t_list *dup);

/*
**	_FT_STR_				FUNCTIONS
*/

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strndup(const char *src, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcasecmp(const char *s1, const char *s2);
int				ft_strncasecmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strrealloc(char **dst, size_t new_size);
void			ft_strdel(char **as);
void			ft_arstrdel(char **ar);
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *str, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
t_bool			ft_strequ(const char *s1, const char *s2);
t_bool			ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *str, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *str);
char			**ft_strsplit(const char *str, char c);
char			**ft_arstrnew(size_t size);
size_t			ft_count_words(const char *str, char seperator);
size_t			ft_strclen(const char *str, char c);
char			*ft_strrev(char *str);

/*
**	_FT_MEM_				FUNCTIONS
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_memclr(void *buffer, size_t size);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_swap(int *a, int *b);
void			ft_swap_addr(void **ap1, void **ap2);
t_byte			ft_swap_byte(const t_byte byte);

/*
**	_FT_PMATCH_				FUNCTIONS
*/

typedef union u_chrmsk	t_chrmsk;

union			u_chrmsk
{
	int		pattern[4];
};

t_chrmsk		new_chrmsk(char *pattern);
t_bool			char_match_pattern(char c, t_chrmsk *cp);
char			**ft_create_wordtab(char *str, t_chrmsk delim);

/*
**	_FT_CONVERT_			FUNCTIONS
*/

int				ft_atoi(const char *str);
int				ft_atoi_base(char *str, char *base);
char			*ft_itoa(int n);
char			*ft_static_itoa(int nb);
char			*ft_itoa_base(int nb, char *base);
int				ft_toupper(int c);
int				ft_tolower(int c);
t_bool			ft_basecheck(char *base);
int				ft_get_basevalue(char value, char *base, int b_height);
t_byte			ft_hexstr_to_byte(char *str);

/*
**	_FT_PUT_				FUNCTIONS
*/

int				ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_putendl(char *str);
void			ft_putnbr(int nb);
int				ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
int				ft_putendl_fd(char *str, int fd);
void			ft_putnbr_fd(int nb, int fd);
void			ft_print_byte(const t_byte byte);

/*
**	_FT_IS_					FUNCTIONS
*/

t_bool			ft_isalpha(int c);
t_bool			ft_isdigit(int c);
t_bool			ft_isalnum(int c);
t_bool			ft_isascii(int c);
t_bool			ft_isprint(int c);
t_bool			ft_isspace(int c);
t_bool			ft_iswhitespace(int c);
t_bool			ft_ishexa(char c);
t_bool			ft_str_iscolorhex(char *str);

/*
**	_FT_MATH_				FUNCTIONS
*/

int				ft_abs(int nb);
int				ft_npow(int n, int pow);
unsigned int	ft_poweroftwo(int n);
int				ft_poweroften(int n);

/*
**	_FT_GNL_				FUNCTIONS
*/

# define BUFF_SIZE		256
# define LF				'\n'

typedef struct s_fd_lst	t_fd_lst;

struct			s_fd_lst
{
	int			fd;
	char		*line;
	t_fd_lst	*next;
};

int				get_next_line(const int fd, char **line);

#endif
