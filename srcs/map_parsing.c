/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:32:47 by jomaia            #+#    #+#             */
/*   Updated: 2025/06/16 16:26:08 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_position *parse_line(char *line, int y)
{
	t_position	*row;
	int			width;
	int			x;

	width = 0;
	x = 0;
	while (line[width])
		width++;
	row = malloc(sizeof(t_position) * width);
	while (x < width)
	{
		row[x].x = x;
		row[x].y = y;
		row[x].c = line[x];
		x++;
	}
	return (row);
}

t_map	*read_map(int fd)
{
	t_map	*map;
	char	*line;

	map = malloc(sizeof(t_map));
	if(!map)
		return(NULL);
	map->position = malloc(sizeof(t_position *) * 1000);
	if (!map->position)
		return(free(map), NULL);
	map->height = 0;
	line = get_next_line(fd);
	printf("%s", line);
	while(line)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if(map->height == 0)
			map->width = ft_strlen(line);
		map->position[map->height] = parse_line(line, map->height);
		free(line);
		map->height++;
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

void	handle_errors(char **matrix)
{
	return ;
}
