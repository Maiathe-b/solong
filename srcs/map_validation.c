/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:48:34 by jomaia            #+#    #+#             */
/*   Updated: 2025/06/25 17:33:44 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	floodfill(t_game *temp, int x, int y, int *coins_found)
{
	if(temp->map.matrix[y - 1][x - 1] == '1' || temp->map.matrix[y - 1][x - 1] == '2')
		return ;
	if(temp->map.matrix[y - 1][x - 1] == 'C')
		*coins_found += 1;
	if(temp->map.matrix[y - 1][x - 1] == 'E')
		temp->valid_exit = 1;
	temp->map.matrix[y - 1][x - 1] = '2';
	floodfill(temp, x - 1, y, coins_found);
	floodfill(temp, x + 1, y, coins_found);
	floodfill(temp, x, y - 1, coins_found);
	floodfill(temp, x, y + 1, coins_found);
}

// static char	**copy_matrix(char **matrix)
// {
// 	char	**copy;
// 	int		i;

// 	i = 0;
// 	while(matrix[i])
// 		i++;
// 	copy = malloc((i - 1) * sizeof(char *));
// 	if(!copy)
// 		return(NULL);
// 	i = 0;
// 	while(copy[i])
// 	{
// 		copy[i] = ft_strdup(matrix[i]);
// 		i++;
// 	}
// 	copy[i] = NULL;
// 	return (copy);
// }

void	validate_map(t_game *game, char **matrix)
{
	t_game	temp;
	int		coins_found;

	coins_found = 0;
	temp = *game;
	if (!temp.map.matrix)
	{
		free_args(matrix);
		print_error("Matrix Error");
	}
	floodfill(&temp, temp.player.x, temp.player.y, &coins_found);
	if(coins_found != game->map.coins || temp.valid_exit != 1)
	{
		free_args(matrix);
		free_args(temp.map.matrix);
		print_error("Invalid Map (no clear path)");
	}
	free_args(temp.map.matrix);
	printf("Mapa valido");
}
