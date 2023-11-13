NAME	:= So_long
CFLAGS	:= -Wextra -Wall -Werror -g3
LIBMLX	:= ./MLX42
BIN		:= ./bin/
MLX 	:= ./MLX42/build/libmlx42.a
HEADERS	:= -I ./includes -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= src/errors.c src/verifications.c src/main.c
OBJS	:= ${SRCS:src/%.c=$(BIN)%.o}
LIBFT_DIR:= ../So_long/lib/42_libft/
PRINTF_DIR	:= ../So_long/lib/Printf
PRINTF_PATH:= ../So_long/lib/Printf/libftprintf.a
LIBFT_PATH:= ../So_long/lib/42_libft/libft.a

LIBS42:= $(LIBFT_PATH) $(PRINTF_PATH)
all: libmlx $(BIN) $(NAME)

$(BIN):
	@mkdir -p $(BIN)

$(MLX):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4


$(BIN)%.o: src/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(MLX) $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(OBJS) $(MLX) $(LIBS) $(HEADERS) $(LIBS42) -o $(NAME)


clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@rm -rf $(BIN)

fclean: clean
	@rm -rf $(NAME)
	rm -rf $(LIBFT_PATH)
	rm -rf $(PRINTF_PATH)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx