/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:25:02 by jomaia            #+#    #+#             */
/*   Updated: 2025/06/30 16:26:32 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	new_position(t_game *game, int new_x, int new_y)
{
	if (game->map.matrix[game->player.y][game->player.x] != 'E')
		game->map.matrix[game->player.y][game->player.x] = '0';
	draw_tile(game, game->images.grass, game->player.x, game->player.y);
	game->player.x = new_x;
	game->player.y = new_y;
	if (game->map.matrix[new_y][new_x] != 'E')
		game->map.matrix[new_y][new_x] = 'P';
	draw_map(game);
}

static int	player_move(t_game *game, int x, int y)
{
	int		new_x;
	int		new_y;
	char	c;

	new_x = game->player.x + x;
	new_y = game->player.y + y;
	c = game->map.matrix[new_y][new_x];
	if (c == '1')
		return (1);
	game->moves++;
	new_position(game, new_x, new_y);
	ft_printf("Moves: %d\n", game->moves);
	if (c == 'C')
	{
		game->coins_capt++;
		if (game->coins_capt == game->map.coins)
			game->exit_opened = 1;
		draw_map(game);
	}
	if (c == 'E' && game->coins_capt == game->map.coins)
	{
		ft_printf("You win");
		close_game(game);
	}
	return (0);
}

int	input(int key, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (key == XK_Escape)
		close_game(game);
	if (key == XK_w)
		player_move(game, 0, -1);
	if (key == XK_a)
		player_move(game, -1, 0);
	if (key == XK_s)
		player_move(game, 0, 1);
	if (key == XK_d)
		player_move(game, 1, 0);
	return(0);
}
