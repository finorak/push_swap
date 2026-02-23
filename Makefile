CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I.

SRCS = main.c utils.c data_free.c error_handler.c \
	   push_swap.c push_swap_command.c stack_utils.c \
	   handle_three.c sort_utils.c medium_sort.c \
	   handle_min.c disorder_metric.c selection_sort.c \
	   bench.c ft_strcmp.c complex_sort.c stack_is_sorted.c \
	   ft_atol.c

BONUS_SRCS = checker_bonus.c checker_bonus_utils.c stack_utils.c \
             utils.c data_free.c error_handler.c ft_strcmp.c \
			 stack_is_sorted.c ft_atol.c

OBJ = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = push_swap

CHECKER = checker

LIBFT_PATH = libft

LIBFT_NAME = libft.a

%.o:%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(LIBFT_PATH)/$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

$(NAME):$(OBJ) $(LIBFT_PATH)/$(LIBFT_NAME)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT_PATH)/$(LIBFT_NAME)

bonus: $(CHECKER)

$(CHECKER): $(BONUS_OBJS) $(LIBFT_PATH)/$(LIBFT_NAME)
	$(CC) $(FLAGS) -o $(CHECKER) $(BONUS_OBJS) $(LIBFT_PATH)/$(LIBFT_NAME)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all re clean fclean bonus
