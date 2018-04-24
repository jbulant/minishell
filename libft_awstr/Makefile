# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbulant <jbulant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:49:28 by jbulant           #+#    #+#              #
#    Updated: 2018/04/24 01:17:50 by jbulant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_awstr.a

LINUX = 0
DEBUG = 0

HEADERS_NAME = ft_awstr.h

SRCS_NAME =	ft_awstrinit.c \
			ft_awpad.c \
			ft_setawstrfd.c \
			ft_awstrlpad.c \
			ft_awstrrpad.c \
			ft_awstrncat.c \
			ft_awstrncatendl.c \
			ft_awstrset.c \
			ft_putawstr.c

OBJDIR = objs/
SRCSDIR = srcs/
HEADERS_PATH = includes/

SRCS = $(addprefix $(SRCSDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

CC = gcc
INCLUDES = -Iincludes -I../libft/includes
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -g3
#DEBUGFLAGS = -fsanitize=address -lasan -g3

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo MODULE [ '\033[0;35m'`echo $(NAME) | sed 's/lib//' | rev | cut -d '.' -f2 | rev | tr a-z A-Z`'\033[0m' ] HAS BEEN COMPILED.

$(OBJDIR)%.o: $(SRCSDIR)%.c ${HEADERS}
	@mkdir -p objs
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [ '\033[0;35m'`echo $(NAME) | sed 's/lib//' | rev | cut -d '.' -f2 | rev | tr a-z A-Z`'\033[0m' - '\033[1;33m'DEBUG'\033[0m' ] converting '\033[1;35m'`echo $< | rev | cut -d'/' -f1 | rev | sed 's/\.c$///g'`'\033[0m';\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [ '\033[0;35m'`echo $(NAME) | sed 's/lib//' | rev | cut -d '.' -f2 | rev | tr a-z A-Z`'\033[0m' ] converting '\033[1;35m'`echo $< | rev | cut -d'/' -f1 | rev | sed 's/\.c$///g'`'\033[0m';\
	fi

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
