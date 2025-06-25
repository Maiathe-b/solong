/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:20:53 by jomaia            #+#    #+#             */
/*   Updated: 2025/06/25 15:52:02 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_coins(char **matrix)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	count = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if(matrix[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	check_height(char **matrix)
{
	int	i;

	i = 0;
	while(matrix[i])
		i++;
	return(i);
}

static void	starting_point(t_game *game, char **matrix)
{
	int	i;
	int	j;

	i = 1;
	while(matrix[i - 1])
	{
		j = 1;
		while (matrix[i- 1][j - 1])
		{
			if (matrix[i - 1][j - 1] == 'P')
			{
				game->player.x = j;
				game->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	create_game(t_game *game, char **matrix)
{
	ft_memset(game, 0, sizeof(t_game));
	game->map.matrix = matrix;
	game->map.coins = count_coins(matrix);
	game->map.height = check_height(matrix);
	game->map.width = ft_strlen(matrix[0]);
	starting_point(game, matrix);
}
