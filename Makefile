NAME=minishell

SRCS_DIR = src
INCL_DIR = includes

SRCS = $(addprefix $(SRCS_DIR)/, main.c prompt_display.c env/env.c builtins/export.c builtins/unset.c builtins/exit.c )
OBJS = $(SRCS:.c=.o)

LIBFT  = lib/libft
LIBS   = -L $(LIBFT) -lft -lreadline -lncurses

INCLUDES = -I $(LIBFT) -I $(INCL_DIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror -pedantic

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT)/libft.a: FORCE
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

FORCE:

clean:
	rm -f $(OBJS)
	make -C $(LIBFT) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
