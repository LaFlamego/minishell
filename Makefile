NAME=minishell

SRCS_DIR = src
INCL_DIR = includes

BASE_SRCS = main.c prompt_display.c signal.c
ENV_SRCS = env.c
BUILTINS_SRCS = env.c exit.c export.c pwd.c unset.c

SRCS = $(addprefix $(SRCS_DIR)/, $(BASE_SRCS))               \
       $(addprefix $(SRCS_DIR)/env/, $(ENV_SRCS))            \
	   $(addprefix $(SRCS_DIR)/builtins/, $(BUILTINS_SRCS))
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
