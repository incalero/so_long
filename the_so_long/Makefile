NAME = so_long
CC = gcc
CFLAGS = -Wall -Werror -Wextra
PRINTF = libftprintf.a
OBJ_DIR = obj
SRC_DIR = src
LIBMLX = libmlx.a
SRC_FILES = main.c \
			ft_good_map.c \
            ft_play_utils.c \
			ft_play.c \
			get_next_line_utils.c \
			get_next_line.c \
			so_long_utils.c \
			so_long.c \


HEADER = so_long.h
LIBC = ar rcs

CLR_RMV     := \033[0m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m

define  ART
$/\n
$(YELLOW):::::::::  :::::::::  ::::::::::: ::::    ::: :::::::::::     ::::::::::     
$(YELLOW):+:    :+: :+:    :+:     :+:     :+:+:   :+:     :+:         :+:             
$(GREEN)+:+    +:+ +:+    +:+     +:+     :+:+:+  +:+     +:+         +:+       
$(GREEN)+#++:++#+  +#++:++#:      +#+     +#+ +:+ +#+     +#+         :#::+::#     
$(CYAN)+#+        +#+    +#+     +#+     +#+  +#+#+#     +#+         +#+     
$(BLUE)#+#        #+#    #+#     #+#     #+#   #+#+#     #+#         #+#             
$(BLUE)###        ###    ### ########### ###    ####     ###         ###              
$(CLR_RMV)
$/\n
endef
export  ART

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) $< -Ilibmlx $^

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: lib $(NAME)

lib:
	make -C ft_printf
	make -C libmlx
	cp ft_printf/$(PRINTF) $(PRINTF)

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) libmlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$$ART"
clean:
	rm -rf $(OBJ_DIR)
	rm -f $(PRINTF)
	make -C ft_printf clean
	make -C libmlx clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re