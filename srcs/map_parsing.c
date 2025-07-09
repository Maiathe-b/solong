/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:32:47 by jomaia            #+#    #+#             */
/*   Updated: 2025/07/08 16:43:32 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_newline(char *line)
{
	int	i;

	i = 1;
	if (!line)
		print_error("Error with line");
	if (line[0] == '\n')
	{
		free(line);
		print_error("Invalid Map (empty line)");
	}
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
		{
			free(line);
			print_error("Invalid Map (empty line)");
		}
		i++;
	}
}

static void	empty_file_check(int bytes_read, char *line)
{
	if (bytes_read == 0)
	{
		free(line);
		print_error("Empty file");
	}
}

char	**read_map(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		bytes_read;
	char	**matrix;
	char	*line;
	char	*aux;

	bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	line = ft_strdup("");
	empty_file_check(bytes_read, line);
	while (bytes_read > 0)
	{
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			aux = line;
			line = ft_strjoin(line, buffer);
			free(aux);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE - 1);
	}
	check_newline(line);
	matrix = ft_split(line, '\n');
	free(line);
	handle_errors(matrix);
	return (matrix);
}
