NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBMLX = libmlx.a
OBJ_DIR = obj

PRINTF = libftprintf.a

SRC_FILES = ft_good_map.c \
            ft_play_utils.c \
			ft_play.c \
			get_next_line_utils.c \
			get_next_line.c \
			so_long_utils.c \
			so_long.c \
			main.c \

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

INCLUDE = so_long.h

all: $(PRINTF) $(NAME) $(LIBMLX)


$(PRINTF):
	make -C ft_printf
	cp ft_printf/$(PRINTF) $(PRINTF)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -o $@ -Ilibmlx 

$(LIBMLX):
	make -C libmlx
	cp libmlx/$(LIBMLX) $(LIBMLX)

$(NAME): $(OBJS) $(INCLUDE) $(LIBMLX) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBMLX) -framework OpenGL -framework AppKit -o $(NAME)


clean:
	rm -rf $(OBJ_DIR)
	rm -f $(PRINTF) $(LIBMLX)
	make -C ft_printf clean
	make -C libmlx clean

fclean: clean
	rm -f $(NAME) 
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re lib