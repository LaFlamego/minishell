NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src
INCLUDE_DIR = include

LST_SRCS  = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c    \
		    ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c                  \
			ft_lstpop_back.c ft_lstpop_front.c ft_lstsize.c

MEM_SRCS  = ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c         \
			ft_memmove.c ft_memset.c ft_strdup.c ft_strldup.c

PUT_SRCS  = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c      \
			ft_putstr_fd_max.c

STR_SRCS  = ft_atoi.c ft_itoa.c ft_split.c ft_strchr.c ft_striteri.c           \
			ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c    \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c    \
			ft_strcmp.c ft_streq.c ft_basename.c ft_endswith.c                 \
			ft_startswith.c ft_split_space.c

GNL_SRCS  = get_next_line.c get_next_line_utils.c

CHAR_SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c   \
			ft_tolower.c ft_toupper.c ft_isspace.c

MATHS_SRCS = ft_abs.c ft_max.c ft_min.c

PRINTF_SRCS = ft_pad.c ft_printf.c ft_printf_char.c ft_printf_flags.c          \
			  ft_printf_hex_l.c ft_printf_hex_u.c ft_printf_nbr.c              \
			  ft_printf_nbr_base.c ft_printf_nbr_u.c ft_printf_nbr_u_base.c    \
			  ft_printf_pct.c ft_printf_ptr.c ft_printf_put.c                  \
			  ft_printf_specs.c ft_printf_str.c ft_read_int.c ft_panic.c       \
			  ft_dprintf.c

ARRAY_SRCS = ft_array.c ft_array_iter.c

STRING_SRCS = ft_string.c

SRCS = $(addprefix $(SRCS_DIR)/lst/, $(LST_SRCS))       \
	   $(addprefix $(SRCS_DIR)/mem/, $(MEM_SRCS))       \
	   $(addprefix $(SRCS_DIR)/put/, $(PUT_SRCS))       \
	   $(addprefix $(SRCS_DIR)/str/, $(STR_SRCS))       \
	   $(addprefix $(SRCS_DIR)/gnl/, $(GNL_SRCS))       \
	   $(addprefix $(SRCS_DIR)/char/, $(CHAR_SRCS))     \
	   $(addprefix $(SRCS_DIR)/array/, $(ARRAY_SRCS))   \
	   $(addprefix $(SRCS_DIR)/maths/, $(MATHS_SRCS))   \
	   $(addprefix $(SRCS_DIR)/string/, $(STRING_SRCS)) \
	   $(addprefix $(SRCS_DIR)/printf/, $(PRINTF_SRCS)) 
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
