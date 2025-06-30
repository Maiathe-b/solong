# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 14:48:47 by jomaia            #+#    #+#              #
#    Updated: 2025/06/30 14:33:36 by jomaia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_DIR = ./lib/libft
MINILIBX_DIR = ./lib/minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX =$(MINILIBX_DIR)/libmlx.a

MAIN = srcs/main.c

SRCS = srcs/map_parsing.c srcs/create_game.c srcs/map_validation.c srcs/utils.c srcs/error_handler.c srcs/init_window.c srcs/movement.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(LIBFT) $(MINILIBX) $(SO_LONG_A) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR)

$(SO_LONG_A): $(OBJS)
	@$(AR) $(SO_LONG_A) $(OBJS)
	@echo 'Biblioteca libso_long.a criada!'

$(NAME): $(OBJS) $(MAIN)
	@$(CC) $(CFLAGS) $(OBJS) $(MAIN) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)
	@echo 'so_long compilado com libft e minilibx!'

mlx_download:
		git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR); \

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f $(SO_LONG_A)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MINILIBX_DIR) clean
	@echo 'Objetos limpos!'

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo 'Tudo limpo!'

re: fclean all

.PHONY: all clean fclean re bonus mlx_download
