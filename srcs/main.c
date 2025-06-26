/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:56:57 by jomaia            #+#    #+#             */
/*   Updated: 2025/06/26 16:57:35 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char **argv)
{
	int		fd;
	char	**map_matrix;
	t_game	game;

	if (argc != 2)
		return 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Could not open file");
	map_matrix = read_map(fd);
	close(fd);
	create_game(&game, map_matrix);
	validate_map(&game, map_matrix);
	init_window(&game);
}
