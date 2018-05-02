# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:49:28 by jbulant           #+#    #+#              #
#    Updated: 2018/05/01 22:14:19 by jbulant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LINUX = 0
DEBUG = 0

HEADERS_NAME = libft.h

SRCS_DIR = \
			ft_convert \
			ft_is \
			ft_lst \
			ft_math \
			ft_mem \
			ft_pmatch \
			ft_put \
			ft_str \
			ft_gnl

SRCS_NAME = \
			ft_convert/ft_atoi_base.c \
			ft_convert/ft_atoi.c \
			ft_convert/ft_basecheck.c \
			ft_convert/ft_get_basevalue.c \
			ft_convert/ft_hexstr_to_byte.c \
			ft_convert/ft_itoa_base.c \
			ft_convert/ft_itoa.c \
			ft_convert/ft_static_itoa.c \
			ft_convert/ft_tolower.c \
			ft_convert/ft_toupper.c \
			ft_is/ft_isalpha.c \
			ft_is/ft_isdigit.c \
			ft_is/ft_isalnum.c \
			ft_is/ft_isascii.c \
			ft_is/ft_isprint.c \
			ft_is/ft_isspace.c \
			ft_is/ft_iswhitespace.c \
			ft_is/ft_ishexa.c \
			ft_is/ft_str_iscolorhex.c \
			ft_lst/ft_lstnew.c \
			ft_lst/ft_lstfromarray.c \
			ft_lst/ft_lstdelone.c \
			ft_lst/ft_lstdel.c \
			ft_lst/ft_lstadd.c \
			ft_lst/ft_lstiter.c \
			ft_lst/ft_lstmap.c \
			ft_lst/ft_lstjoin.c \
			ft_lst/ft_lstappend.c \
			ft_lst/ft_lstsort.c \
			ft_lst/ft_lstprint.c \
			ft_lst/ft_lstrprint.c \
			ft_lst/ft_lstprint_content.c \
			ft_lst/ft_lstdup.c \
			ft_mem/ft_memset.c \
			ft_mem/ft_bzero.c \
			ft_mem/ft_memcpy.c \
			ft_mem/ft_memccpy.c \
			ft_mem/ft_memmove.c \
			ft_mem/ft_memchr.c \
			ft_mem/ft_memcmp.c \
			ft_mem/ft_memclr.c \
			ft_mem/ft_memalloc.c \
			ft_mem/ft_memdel.c \
			ft_mem/ft_swap.c \
			ft_mem/ft_swap_addr.c \
			ft_mem/ft_swap_byte.c \
			ft_pmatch/char_match_pattern.c \
			ft_pmatch/create_char_pattern.c \
			ft_pmatch/ft_create_wordtab.c \
			ft_put/ft_print_byte.c \
			ft_put/ft_putchar.c \
			ft_put/ft_putchar_fd.c \
			ft_put/ft_putstr.c \
			ft_put/ft_putstr_fd.c \
			ft_put/ft_putendl.c \
			ft_put/ft_putendl_fd.c \
			ft_put/ft_putnbr.c \
			ft_put/ft_putnbr_fd.c \
			ft_str/ft_strlen.c \
			ft_str/ft_strdup.c \
			ft_str/ft_strndup.c \
			ft_str/ft_strcpy.c \
			ft_str/ft_strncpy.c \
			ft_str/ft_strcat.c \
			ft_str/ft_strncat.c \
			ft_str/ft_strlcat.c \
			ft_str/ft_strchr.c \
			ft_str/ft_strrchr.c \
			ft_str/ft_strstr.c \
			ft_str/ft_strnstr.c \
			ft_str/ft_strcmp.c \
			ft_str/ft_strncmp.c \
			ft_str/ft_strnew.c \
			ft_str/ft_strrealloc.c \
			ft_str/ft_strdel.c \
			ft_str/ft_arstrdel.c \
			ft_str/ft_strclr.c \
			ft_str/ft_striter.c \
			ft_str/ft_striteri.c \
			ft_str/ft_strmap.c \
			ft_str/ft_strmapi.c \
			ft_str/ft_strequ.c \
			ft_str/ft_strnequ.c \
			ft_str/ft_strsub.c \
			ft_str/ft_strjoin.c \
			ft_str/ft_strtrim.c \
			ft_str/ft_strsplit.c \
			ft_str/ft_arstrnew.c \
			ft_str/ft_count_words.c \
			ft_str/ft_strclen.c \
			ft_str/ft_strrev.c \
			ft_gnl/get_next_line.c

OBJ_ROOTDIR = objs/
OBJ_VDIR = $(addprefix $(OBJ_ROOTDIR),$(SRCS_DIR))
SRCS_ROOTDIR = srcs/
HEADERS_PATH = includes/
HEADERS_NAME = libft.h

SRCS = $(addprefix $(SRCS_ROOTDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJ_ROOTDIR),$(SRCS_NAME:.c=.o))
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

CC = gcc
INCLUDES = -Iincludes
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -g3
# DEBUGFLAGS = -g3

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo LIBRARY [ '\033[0;32m'`echo $(NAME) | rev | cut -d '.' -f2 | rev| tr a-z A-Z`'\033[0m' ] HAS BEEN COMPILED.

$(OBJ_ROOTDIR)%.o: $(SRCS_ROOTDIR)%.c ${HEADERS}
	@mkdir -p $(OBJ_VDIR)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [ '\033[0;32m'`echo $(NAME) | rev | cut -d '.' -f2 | rev| tr a-z A-Z`'\033[0m' - '\033[1;33m'DEBUG'\033[0m' ] converting '\033[1;32m'`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`'\033[0m';\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [ '\033[0;32m'`echo $(NAME) | rev | cut -d '.' -f2 | rev| tr a-z A-Z`'\033[0m' ] converting '\033[1;32m'`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`'\033[0m';\
	fi

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_ROOTDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
