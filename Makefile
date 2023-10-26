NAME = so_long.a
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

HEADER = .
SRCS = teste.c 

OBJS =  $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

.PHONY: clean fclean re all bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all