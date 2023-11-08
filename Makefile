NAME	:= So_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./includes -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}
GNL		:= /nfs/homes/matesant/So_long/lib/Get_next_line
LIBFT_DIR:= /nfs/homes/matesant/So_long/lib/42_libft/
PRINTF_DIR	:= /nfs/homes/matesant/So_long/lib/Printf
GNL_PATH:= /nfs/homes/matesant/So_long/lib/Get_next_line/get_next_line.a
PRINTF_PATH:= /nfs/homes/matesant/So_long/lib/Printf/libftprintf.a
LIBFT_PATH:= /nfs/homes/matesant/So_long/lib/42_libft/libft.a

LIBS42:= $(GNL_PATH) $(LIBFT_PATH) $(PRINTF_PATH)
all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@make -C $(GNL)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBS42) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@make clean -C $(GNL)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	@rm -rf $(NAME)
	rm -rf $(LIBFT_PATH)
	rm -rf $(GNL_PATH)
	rm -rf $(PRINTF_PATH)

re: clean all

.PHONY: all, clean, fclean, re, libmlx