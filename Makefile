NAME=minishell

SRCS_DIR = src
INCL_DIR = includes

BASE_SRCS = main.c prompt_display.c
ENV_SRCS = env.c env_find.c env_from.c env_merge.c env_set_exit_code.c
CTX_SRCS = ctx_init.c
CMD_SRCS = cmd.c
CMD_EXEC_SRCS = exec_bin.c exec_cmd.c exec_fork.c exec_path.c
PARSE_SRCS = parse_command.c parse_string.c parse_utils.c
EXPAND_SRCS = expand_command.c expand_dollar.c expand_word.c
BUILTINS_SRCS = echo.c env.c exit.c export.c pwd.c unset.c cd.c

SRCS = $(addprefix $(SRCS_DIR)/, $(BASE_SRCS))               \
       $(addprefix $(SRCS_DIR)/env/, $(ENV_SRCS))            \
       $(addprefix $(SRCS_DIR)/ctx/, $(CTX_SRCS))            \
       $(addprefix $(SRCS_DIR)/cmd/, $(CMD_SRCS))            \
       $(addprefix $(SRCS_DIR)/cmd/exec/, $(CMD_EXEC_SRCS))  \
       $(addprefix $(SRCS_DIR)/cmd/parse/, $(PARSE_SRCS))    \
       $(addprefix $(SRCS_DIR)/cmd/expand/, $(EXPAND_SRCS))  \
	   $(addprefix $(SRCS_DIR)/builtins/, $(BUILTINS_SRCS))
OBJS = $(SRCS:.c=.o)

LIBFT  = lib/libft
LIBS   = -L $(LIBFT) -lft -lreadline -lncurses

INCLUDES = -I $(LIBFT)/ -I $(INCL_DIR)

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
