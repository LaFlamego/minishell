NAME=minishell

SRCS_DIR = ./src
INCL_DIR = ./

BASE_SRCS = main.c
ENV_SRCS = env.c env_find.c env_from.c env_merge.c env_set_exit_code.c
CTX_SRCS = ctx_init.c
CMD_SRCS = cmd.c cmd_quotes.c
CMD_EXEC_SRCS = exec_bin.c exec_cmd.c exec_fork.c exec_path.c
PROMPT_SRCS = prompt_display.c
EXPAND_SRCS = expand_command.c expand_dollar.c expand_word.c expand_wildcard.c
BUILTINS_SRCS = echo.c env.c exit.c export.c pwd.c unset.c cd.c
FILES_SRCS = dir.c

TOKEN_SRCS = token_new.c token_scan.c token_scan_blank.c token_scan_string.c token_scan_ident.c token_utils.c
SCANNER_SRCS = scanner_new.c scanner_add_token.c scanner_error.c scanner_scan.c

SRCS = $(addprefix $(SRCS_DIR)/, $(BASE_SRCS))               \
       $(addprefix $(SRCS_DIR)/env/, $(ENV_SRCS))            \
       $(addprefix $(SRCS_DIR)/ctx/, $(CTX_SRCS))            \
       $(addprefix $(SRCS_DIR)/cmd/, $(CMD_SRCS))            \
       $(addprefix $(SRCS_DIR)/cmd/exec/, $(CMD_EXEC_SRCS))  \
       $(addprefix $(SRCS_DIR)/cmd/expand/, $(EXPAND_SRCS))  \
       $(addprefix $(SRCS_DIR)/files/, $(FILES_SRCS))        \
       $(addprefix $(SRCS_DIR)/prompt/, $(PROMPT_SRCS))      \
       $(addprefix $(SRCS_DIR)/scanner/, $(SCANNER_SRCS))    \
       $(addprefix $(SRCS_DIR)/scanner/token/, $(TOKEN_SRCS))    \
	   $(addprefix $(SRCS_DIR)/builtins/, $(BUILTINS_SRCS))
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

LIBFT  = lib/libft
LIBS   = -L $(LIBFT) -lft -lreadline -lncurses

INCLUDES = -I $(LIBFT)/ -I $(INCL_DIR)

CC = cc
CFLAGS = -MMD -Wall -Wextra -Werror -pedantic

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(LIBFT)/libft.a: FORCE
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

-include $(DEPS)

FORCE:

clean:
	rm -f $(OBJS) $(DEPS)
	make -C $(LIBFT) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
