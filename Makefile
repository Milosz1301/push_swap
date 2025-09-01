NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC =  main.c core.c cost_target.c cost_op.c op_ab.c op_a.c op_b.c \
       parsing.c print_check.c push.c stack_utils.c utils.c utils2.c

BIN = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(BIN)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $^
clean:
	$(RM) $(BIN)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
