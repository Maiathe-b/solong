/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:56:57 by jomaia            #+#    #+#             */
/*   Updated: 2025/06/23 16:52:20 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char **argv)
{
	int		fd;
	char	**map_matrix;
	t_game	game;
	t_map	*map;

	if (argc != 2)
		return 0;
	fd = open(argv[1], O_RDONLY);
	//if (fd < 0)
	//	exit_with_perror("Could not open file");
	map = read_map(fd);
}
