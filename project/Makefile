NAME		= push_swap
NAME_BONUS	= checker
CC			= clang
FLAGS		= -O3 -Wall -Wextra -Werror
RM			= rm -rf
AR			= ar rc
INC			= -I ./inc
LIBFT		= libft/libft.a

SRCS_PATH	= ./src/
OBJS_PATH	= ./objs/

SRCS_NAME	=	main.c check_errors.c exit_func.c create_lists.c \
				stack_operations1.c stack_operations2.c \
				predsort.c predsort2.c sort.c sort2.c sort3.c \
				minisort.c
SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS_NAME:.c=.o))

B_SRCS_NAME	=	checker.c get_next_line.c get_next_line_utils.c \
				stack_operations1.c stack_operations2.c exit_func.c \
				check_errors.c create_lists.c
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

clean: clean_libft
	$(RM) $(OBJS_PATH)

clean_libft:
	@make clean -C ./libft

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	$(RM) $(LIBFT)

re:			fclean all

bonus:	$(LIBFT) $(NAME) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_PATH) $(BONUS_OBJS)
	$(CC) $(FLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME_BONUS)

.PHONY: all clean fclean re bonus
