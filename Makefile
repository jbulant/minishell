NAME = minishell

DEBUG = 0

LIBFTDIR = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFTDIR)$(LIBFT_NAME)

OBJDIR = objs/
SRCSDIR = srcs/

SRCS_NAME = main.c \
			minishell_init.c \
			getusr.c \
			parse_input.c \
			ft_perror.c \
			get_next_line.c \
			builtin/env.c

SRCS = $(addprefix $(SRCSDIR),$(SRCS_NAME))
OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))

INCLUDES = -Iincludes -Ilibft/includes

LIBS = -L $(LIBFTDIR) -lft

CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -fsanitize=address -lasan -g3

HEADERS_PATH = includes/
HEADERS_NAME =	minishell.h \
				get_next_line.h \
				ft_error.h \
				msh_builtin.h
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJDIR)%.o: $(SRCSDIR)%.c ${HEADERS}
	@mkdir -p objs/builtin
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [$(NAME)][DEBUG]converting: `echo $< | rev | cut -d'/' -f1 | rev`;\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<;\
		echo [$(NAME)]converting: `echo $< | rev | cut -d'/' -f1 | rev`;\
	fi

$(LIBFT):
	@make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	@if [ $(DEBUG) -eq 1 ];\
	then\
		$(CC) $(CFLAGS) $(DEBUGFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME);\
	else\
		$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS) -o $(NAME);\
	fi
	@echo PROGRAM: $(NAME) HAS BEEN COMPILED.

clean:
	rm -f $(OBJS)
	rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean
	@make -C $(FT_ADV_LSTDIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean
	@make -C $(FT_ADV_LSTDIR) fclean

re: fclean all
