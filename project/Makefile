NAME		= push_swap
CC			= clang
FLAGS		= -g -Wall -Wextra -Werror
RM			= rm -rf
AR			= ar rc
INC			= -I ./inc
LIBFT		= libft/libft.a

SRCS_PATH	= ./src/
OBJS_PATH	= ./objs/

SRCS_NAME	=	main.c check_errors.c exit_func.c create_lists.c \
				stack_operations1.c stack_operations2.c \
				predsort.c predsort2.c
SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS_NAME:.c=.o))

B_SRCS_NAME	=
BONUS_SRCS	= $(addprefix $(SRCS_PATH), $(B_SRCS_NAME))
BONUS_OBJS	= $(addprefix $(OBJS_PATH), $(B_SRCS_NAME:.c=.o))

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) -c $(FLAGS) $(INC) $< -o $@

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

$(LIBFT):
	@make -C ./libft

clean:
	$(RM) $(OBJS_PATH)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

bonus:

.PHONY: all clean fclean re bonus
