/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:44:14 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/01 17:21:40 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	size_check(char **matrix)
{
	int	i;

	i = 0;
	while(matrix[i] && matrix[i + 1])
	{
		if (ft_strlen(matrix[i]) != ft_strlen(matrix[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

static int	char_check(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while(matrix[i])
	{
		j = 0;
		while(matrix[i][j])
		{
			if (matrix[i][j] != '1' && matrix[i][j] != '0'
				&& matrix[i][j] != 'C' && matrix[i][j] != 'P' && matrix[i][j] != 'E')
					return (1);
			j++;
		}
		i++;
	}
	return(0);
}

static int	count_objects(char **matrix, int coins, int exit, int player)
{
	int	i;
	int	j;

	i = 0;
	while(matrix[i])
	{
		j = 0;
		while(matrix[i][j])
		{
			if(matrix[i][j] == 'C')
				coins++;
			if(matrix[i][j] == 'E')
				exit++;
			if(matrix[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (coins < 1 || player != 1 || exit != 1)
		return (1);
	return (0);
}

static int	outline(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while(matrix[i])
	{
		j = 0;
		if(i == 0 || !matrix[i + 1])
		{
			while (matrix[i][j])
			{
				if (matrix[i][j] != '1')
					return(1);
				j++;
			}
		}
		else
			if(matrix[i][0] != '1' || matrix[i][ft_strlen(matrix[i]) - 1] != '1')
				return (1);
		i++;
	}
	return(0);
}

void	handle_errors(char **matrix)
{
	if(!matrix)
	{
		free_args(matrix);
		print_error("Matrix failure");
	}
	if (size_check(matrix))
	{
		free_args(matrix);
		print_error("Invalid Map");
	}
	if (char_check(matrix))
	{
		free_args(matrix);
		print_error("Invalid character in Matrix");
	}
	if(count_objects(matrix, 0, 0, 0))
	{
		free_args(matrix);
		print_error("Check number of players, exits or collectibles");
	}
	if(outline(matrix))
	{
		free_args(matrix);
		print_error("Outline of Map needs to be walls (1)");
	}
}
