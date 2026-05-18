NAME = minishell

SRCS_DIR = ./src
INCL_DIR = ./

BASE_SRCS = main.c

ENV_SRCS	= 	env.c				\
				env_find.c			\
				env_from.c			\
				env_set.c			\
				env_set_exit_code.c

CTX_SRCS = ctx_init.c
CMD_SRCS = cmd.c cmd_quotes.c
CMD_EXEC_SRCS = exec_bin.c exec_cmd.c exec_fork.c exec_init.c       			\
				exec_ops_and_or.c exec_ops_cmd.c exec_ops_pipe.c		        \
				exec_pipeline.c exec_track_node.c exec_utils.c exec_redir_dup.c

PATH_SRCS	=	path_access.c		\
				path_error.c		\
				path_get_bin.c		\
				path_get_cmd.c

PROMPT_SRCS = prompt_display.c
BUILTINS_SRCS = echo.c env.c exit.c export.c pwd.c unset.c cd.c

SCANNER_SRCS = scanner_new.c scanner_add_token.c scanner_error.c scanner_scan.c

TOKEN_SRCS =	token_new.c			\
				token_scan.c		\
				token_scan_blank.c	\
				token_scan_ident.c	\
				token_scan_string.c	\
				token_utils.c

PARSER_SRCS = 	parser_new.c				\
				parser_error.c				\
				parser_match.c				\
				parse.c						\
				parse_binary.c				\
				parse_cmd.c					\
				parse_cmd_arg.c				\
				parse_cmd_word.c			\
				parse_pipe.c				\
				parse_primary.c				\
				parse_variable.c

NODE_SRCS 	=	node.c						\
				node_free.c					\
				node_traverse.c

WORD_SRCS	=	word.c						\
				word_part.c

EXPAND_SRCS	=	expand_command.c			\
				expand_files.c				\
				expand_heredoc.c			\
				expand_redirections.c		\
				expand_redirections_setup.c	\
				expand_target.c				\
				expand_word.c

UTILS_SRCS	=	cli.c			\
				files.c			\
				files_filter.c	\
				files_utils.c	\
				signals.c

DEBUG_SRCS	=	debug_argv.c			\
				debug_node.c			\
				debug_node_utils.c		\
				debug_token.c			\
				debug_word.c

SRCS = $(addprefix $(SRCS_DIR)/, $(BASE_SRCS))					\
       $(addprefix $(SRCS_DIR)/env/, $(ENV_SRCS))				\
       $(addprefix $(SRCS_DIR)/ctx/, $(CTX_SRCS))				\
       $(addprefix $(SRCS_DIR)/cmd/, $(CMD_SRCS))				\
       $(addprefix $(SRCS_DIR)/cmd/exec/, $(CMD_EXEC_SRCS))     \
       $(addprefix $(SRCS_DIR)/cmd/exec/path/, $(PATH_SRCS))    \
       $(addprefix $(SRCS_DIR)/debug/, $(DEBUG_SRCS))			\
       $(addprefix $(SRCS_DIR)/cmd/expand/, $(EXPAND_SRCS))		\
       $(addprefix $(SRCS_DIR)/files/, $(FILES_SRCS))			\
       $(addprefix $(SRCS_DIR)/prompt/, $(PROMPT_SRCS))			\
       $(addprefix $(SRCS_DIR)/scanner/, $(SCANNER_SRCS))		\
       $(addprefix $(SRCS_DIR)/scanner/token/, $(TOKEN_SRCS))	\
       $(addprefix $(SRCS_DIR)/parser/, $(PARSER_SRCS))			\
       $(addprefix $(SRCS_DIR)/cmd/tree/, $(NODE_SRCS))			\
       $(addprefix $(SRCS_DIR)/cmd/tree/word/, $(WORD_SRCS))	\
	   $(addprefix $(SRCS_DIR)/builtins/, $(BUILTINS_SRCS))		\
	   $(addprefix $(SRCS_DIR)/utils/, $(UTILS_SRCS))
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
