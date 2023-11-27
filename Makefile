NAME	:= So_long
NAME_BONUS	:= So_long_bonus
CFLAGS	:= -Wextra -Wall -Werror -g3
LIBMLX	:= ./MLX42
BIN		:= ./bin/
MLX 	:= ./MLX42/build/libmlx42.a
HEADERS	:= -I ./includes -I $(LIBMLX)/include
HEADERS_BONUS	:= -I ./includes_bonus -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:=  src/hooks.c src/image_creation.c src/init_mlx.c src/errors.c src/verifications.c src/flood_fill.c src/main.c
SRCS_BONUS	:=  src_bonus/hooks_bonus.c src_bonus/image_creation_bonus.c src_bonus/init_mlx_bonus.c src_bonus/errors_bonus.c src_bonus/verifications_bonus.c src_bonus/flood_fill_bonus.c src_bonus/main_bonus.c
OBJS	:= ${SRCS:src/%.c=$(BIN)%.o}
OBJS_BONUS	:= ${SRCS_BONUS:src_bonus/%.c=%.o}
LIBFT_DIR:= ../So_long/lib/42_libft/
PRINTF_DIR	:= ../So_long/lib/Printf/
GNL_DIR		:= ../So_long/lib/Get_next_line/
GNL_PATH	:= ../So_long/lib/Get_next_line/get_next_line.a
PRINTF_PATH:= ../So_long/lib/Printf/libftprintf.a
LIBFT_PATH:= ../So_long/lib/42_libft/libft.a
LIBS42:= $(LIBFT_PATH) $(PRINTF_PATH) $(GNL_PATH)

all: libmlx $(BIN) $(NAME)
bonus: libmlx $(NAME_BONUS)

$(BIN):
	@mkdir -p $(BIN)

$(MLX):
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(BIN)%.o: src/%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

%.o: src/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<
	
$(NAME): $(OBJS) $(MLX)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(GNL_DIR)
	@$(CC) $(OBJS) $(MLX) $(LIBS) $(HEADERS) $(LIBS42) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(MLX)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(GNL_DIR)
	@$(CC) $(OBJS_BONUS) $(MLX) $(LIBS) $(LIBS42) $(HEADERS_BONUS) -o $(NAME_BONUS)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(GNL_DIR)
	@rm -rf $(BIN)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT_PATH)
	@rm -rf $(PRINTF_PATH)
	@rm -rf $(GNL_PATH)

re: fclean all

.PHONY: all bonus clean fclean re libmlx