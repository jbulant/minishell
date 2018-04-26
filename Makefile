NAME = minishell

LINUX = 0
DEBUG = 0

LIBFTDIR = libft/
LIBFT_NAME = libft.a

LIBFT = $(LIBFTDIR)$(LIBFT_NAME)

LIBFTSTACK_DIR = libft_stack/
LIBFTSTACK_NAME = libft_stack.a

LIBFTSTACK = $(LIBFTSTACK_DIR)$(LIBFTSTACK_NAME)

LIBFTAWSTR_DIR = libft_awstr/
LIBFTAWSTR_NAME = libft_awstr.a

LIBFTAWSTR = $(LIBFTAWSTR_DIR)$(LIBFTAWSTR_NAME)

OBJDIR = objs/
SRCSDIR = srcs/

SRCS_NAME = main.c \
			minishell_init.c \
			new_argbuffer.c \
			getusr.c \
			parse_input.c \
			ft_exec_cmd.c \
			check_builtins.c \
			ft_perror.c \
			get_next_line.c \
			create_char_pattern.c \
			char_match_pattern.c \
			ft_create_wordtab.c \
			builtin/create_builtins.c \
			builtin/env_tools.c \
			builtin/env_toarray.c \
			builtin/env.c \
			builtin/setenv.c \
			builtin/unsetenv.c \
			builtin/ft_echo.c \
			builtin/sh_exit.c

SRCS = $(addprefix $(SRCSDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))

INCLUDES =	-Iincludes \
			-I$(LIBFTDIR)includes \
			-I$(LIBFTSTACK_DIR)includes \
			-I$(LIBFTAWSTR_DIR)includes

LIBS =	-L $(LIBFTDIR) -lft \
 		-L $(LIBFTSTACK_DIR) -lft_stack \
 		-L $(LIBFTAWSTR_DIR) -lft_awstr

CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -g3
#DEBUGFLAGS = -fsanitize=address -lasan -g3

HEADERS_PATH = includes/
HEADERS_NAME =	minishell.h \
				get_next_line.h \
				ft_error.h \
				msh_builtin.h \
				msh_token.h \
				ft_pmatch.h

HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c ${HEADERS}
	@mkdir -p objs/builtin
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [ '\033[0;31m'`echo $(NAME) | tr a-z A-Z`'\033[0m' - '\033[1;33m'DEBUG'\033[0m' ] converting '\033[1;31m'`echo $< | rev | cut -d'/' -f1 | rev | sed 's/\.c$///g'`'\033[0m';\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [ '\033[0;31m'`echo $(NAME) | tr a-z A-Z`'\033[0m' ] converting '\033[1;31m'`echo $< | rev | cut -d'/' -f1 | rev | sed 's/\.c$///g'`'\033[0m';\
	fi

$(LIBFT):
	@make -C $(LIBFTDIR)

$(LIBFTSTACK):
	@make -C $(LIBFTSTACK_DIR)

$(LIBFTAWSTR):
	@make -C $(LIBFTAWSTR_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBFTSTACK) $(LIBFTAWSTR)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $(NAME) $(INCLUDES) $(OBJS) $(LIBS);\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBS);\
	fi
	@echo PROGRAM [ '\033[0;31m'`echo $(NAME) | tr a-z A-Z`'\033[0m' ] HAS BEEN COMPILED.

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	@make -C $(LIBFTSTACK_DIR) clean
	@make -C $(LIBFTAWSTR_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@make -C $(LIBFTSTACK_DIR) fclean
	@make -C $(LIBFTAWSTR_DIR) fclean

re: fclean all
