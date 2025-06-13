/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:39:47 by jomaia            #+#    #+#             */
/*   Updated: 2025/06/10 12:03:14 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			readbytes;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (*buffer != '\0')
		line = ft_strjoin(line, buffer);
	while (find_new_line(line) == -1)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes < 0)
		{
			buffer[0] = '\0';
			return (free(line), NULL);
		}
		if (readbytes == 0)
			break ;
		buffer[readbytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	reset_buffer(buffer);
	return (line);
}

// int main(void)
// {
// 	int	i;
// 	int	fd = open("test1.txt", O_RDONLY);
// 	char *line;

// 	i = 0;

// 	while (i < 10)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	close(fd);
// }
