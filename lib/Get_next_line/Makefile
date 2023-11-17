NAME = get_next_line.a
CC = cc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

HEADER = .
SRCS = get_next_line.c get_next_line_utils.c

OBJS =  $(SRCS:.c=.o)

.PHONY: clean fclean re all bonus

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all