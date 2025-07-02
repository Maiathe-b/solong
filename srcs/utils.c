/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:45:41 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/02 11:55:55 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
}

void	free_all(t_game *game)
{
	if (game->images.collectable)
		mlx_destroy_image(game->mlx, game->images.collectable);
	if (game->images.exit)
		mlx_destroy_image(game->mlx, game->images.exit);
	if (game->images.player)
		mlx_destroy_image(game->mlx, game->images.player);
	if (game->images.water)
		mlx_destroy_image(game->mlx, game->images.water);
	if (game->images.grass)
		mlx_destroy_image(game->mlx, game->images.grass);
	if (game->images.player_exit)
		mlx_destroy_image(game->mlx, game->images.player_exit);
	if (game->images.exit_open)
		mlx_destroy_image(game->mlx, game->images.exit_open);
	free_args(game->map.matrix);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
}

void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}

int	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_all(game);
	exit(0);
	return (0);
}
