# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 14:48:47 by jomaia            #+#    #+#              #
#    Updated: 2025/06/16 15:45:46 by jomaia           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT_DIR = ./lib/libft
MINILIBX_DIR = ./lib/minilibx-linux
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX =$(MINILIBX_DIR)/libmlx.a

MAIN = main.c

SRCS = map_parsing.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -Llib/minilibx-linux/ -lmlx_Linux -lXext -lX11
AR = ar rcs

all: $(LIBFT) $(MINILIBX) $(SO_LONG_A) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MINILIBX_DIR)

$(SO_LONG_A): $(OBJS)
	@$(AR) $(SO_LONG_A) $(OBJS)
	@echo 'Biblioteca libso_long.a criada!'

$(NAME): $(OBJS) $(MAIN)
	@$(CC) $(CFLAGS) $(OBJS) $(MAIN) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)
	@echo 'so_long compilado com libft e minilibx!'

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(MLX) $(BONUS_OBJS) $(BONUS_MAIN)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(BONUS_MAIN) -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm -o $(BONUS_NAME)
	@echo 'so_long_bonus compilado com libft e minilibx!'

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
