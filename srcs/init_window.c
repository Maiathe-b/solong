/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:55:54 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/08 16:09:41 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_images(t_game *game)
{
	int	height;
	int	width;

	game->images.collectable = mlx_xpm_file_to_image(game->mlx,
			"img/Collectable.xpm", &width, &height);
	game->images.player = mlx_xpm_file_to_image(game->mlx,
			"img/character.xpm", &width, &height);
	game->images.exit = mlx_xpm_file_to_image(game->mlx,
			"img/exit_closed.xpm", &width, &height);
	game->images.exit_open = mlx_xpm_file_to_image(game->mlx,
			"img/Exit_open.xpm", &width, &height);
	game->images.water = mlx_xpm_file_to_image(game->mlx,
			"img/water.xpm", &width, &height);
	game->images.grass = mlx_xpm_file_to_image(game->mlx,
			"img/grass.xpm", &width, &height);
	game->images.player_exit = mlx_xpm_file_to_image(game->mlx,
			"img/Player_on_exit.xpm", &width, &height);
	if (!game->images.collectable || !game->images.player
		|| !game->images.exit || !game->images.exit_open
		|| !game->images.water || !game->images.grass
		|| !game->images.player_exit)
	{
		free_all(game);
		print_error("Images init error");
	}
}

static void	draw_map2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == 'P')
				mlx_put_image_to_window(game->mlx,
					game->window, game->images.player, j * 64, i * 64);
			if (game->map.matrix[i][j] == 'E' && game->exit_opened == 0)
				mlx_put_image_to_window(game->mlx,
					game->window, game->images.exit, j * 64, i * 64);
			else if (game->map.matrix[i][j] == 'E' && game->exit_opened == 1)
				mlx_put_image_to_window(game->mlx,
					game->window, game->images.exit_open, j * 64, i * 64);
			else if (game->map.matrix[i][j] == 'F')
				mlx_put_image_to_window(game->mlx,
					game->window, game->images.player_exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i])
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == '1')
				mlx_put_image_to_window(game->mlx,
					game->window, game->images.water, j * 64, i * 64);
			if (game->map.matrix[i][j] == '0')
				mlx_put_image_to_window(game->mlx,
					game->window, game->images.grass, j * 64, i * 64);
			if (game->map.matrix[i][j] == 'C')
				mlx_put_image_to_window(game->mlx,
					game->window, game->images.collectable, j * 64, i * 64);
			j++;
		}
		i++;
	}
	draw_map2(game);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_args(game->map.matrix);
		print_error("Window initialization error");
	}
	game->window = mlx_new_window(game->mlx,
			game->map.width * 64, game->map.height * 64, "so_long");
	if (!game->window)
	{
		free_args(game->map.matrix);
		mlx_destroy_display(game->mlx);
		print_error("Window opening error");
	}
	draw_images(game);
	draw_map(game);
}
