/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:56:57 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/08 14:43:31 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**map_matrix;
	t_game	game;

	if (argc != 2)
		return (0);
	if (ft_strlen(argv[1]) < 4
		|| !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		print_error("Invalid file");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Could not open file");
	map_matrix = read_map(fd);
	close(fd);
	create_game(&game, map_matrix);
	validate_map(&game, map_matrix);
	init_window(&game);
	mlx_hook(game.window, 2, 1L << 0, input, &game);
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	free_args(map_matrix);
	free_all(&game);
}
