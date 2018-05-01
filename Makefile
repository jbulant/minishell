NAME = minishell

LINUX = 0
DEBUG = 0

LIBFTDIR = libft/
LIBFT_NAME = libft.a

LIBFT = $(LIBFTDIR)$(LIBFT_NAME)

SRCS_DIR =	\
			tools \
			builtin \
			builtin/common \
			builtin/tools

SRCS_NAME = \
			main.c \
			getusr.c \
			parse_input.c \
			tools/ft_perror.c \
			tools/minishell_init.c \
			tools/new_argbuffer.c \
			tools/virtual_env.c \
			builtin/env.c \
			builtin/setenv.c \
			builtin/unsetenv.c \
			builtin/ft_echo.c \
			builtin/ft_cd.c \
			builtin/sh_exit.c \
			builtin/ft_exec_cmd.c \
			builtin/common/check_builtins.c \
			builtin/common/create_builtins.c \
			builtin/tools/env_tools.c \
			builtin/tools/cd_tools.c \
			builtin/tools/env_gset.c \
			builtin/tools/env_toarray.c

INCLUDES =	-Iincludes \
			-I$(LIBFTDIR)includes

OBJ_ROOTDIR = objs/
SRCS_ROOTDIR = srcs/

LIBS =	-L $(LIBFTDIR) -lft

CFLAGS = -Wall -Wextra -Werror
# DEBUGFLAGS = -fsanitize=address -g3
DEBUGFLAGS = -g3

HEADERS_PATH =	includes/
HEADERS_NAME =	minishell.h \
				ft_error.h \
				msh_builtin.h

CC = gcc

OBJ_VDIR = $(addprefix $(OBJ_ROOTDIR), $(SRCS_DIR))
SRCS = $(addprefix $(SRCS_ROOTDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJ_ROOTDIR),$(SRCS_NAME:.c=.o))
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_ROOTDIR)%.o: $(SRCS_ROOTDIR)%.c ${HEADERS}
	@mkdir -p $(OBJ_VDIR)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [ '\033[0;31m'`echo $(NAME) | tr a-z A-Z`'\033[0m' - '\033[1;33m'DEBUG'\033[0m' ] converting '\033[1;31m'`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`'\033[0m';\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [ '\033[0;31m'`echo $(NAME) | tr a-z A-Z`'\033[0m' ] converting '\033[1;31m'`echo $< | sed 's/^srcs\///g' | sed 's/\.c$///g'`'\033[0m';\
	fi

$(LIBFT):
	@make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBS);\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS);\
	fi
	@echo PROGRAM [ '\033[0;31m'`echo $(NAME) | tr a-z A-Z`'\033[0m' ] HAS BEEN COMPILED.

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_ROOTDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all
