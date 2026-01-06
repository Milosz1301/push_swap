NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -I include

MKDIR = mkdir -p
RMDIR = rm -rf

SRC =  main.c core_operations.c cost_target.c cost_operations.c ab_stack_operations.c \
       a_stack_operations.c b_stack_operations.c parsing.c print_check.c push_operations.c \
       stack_utils.c utils.c utils2.c

OBJ = $(SRC:.c=.o)
OBJ := $(addprefix obj/,$(OBJ))

OBJ_DIR = obj/

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c -o $@ $^

$(OBJ_DIR):
	$(MKDIR) $@

clean:
	$(RMDIR) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
