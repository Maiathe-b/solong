/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:00:40 by jomaia            #+#    #+#             */
/*   Updated: 2025/06/24 15:23:29 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_image
{
	void		*coin;
	void		*exit;
	void		*wall;
	void		*ground;
	void		*player;
	void		*exit_open;
	void		*player_exit;
}				t_image;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_map
{
	int			coins;
	int			width;
	int			height;
	t_position	**position;
}				t_map;

typedef struct s_game
{
	int			moves;
	int			valexit;
	int			coins_capt;
	int			exit_opened;
	void		*mlx;
	void		*window;
	t_map		map;
	t_image		images;
	t_position	player;
}				t_game;

char	**read_map(int fd);
void	print_error(char *msg);
void	handle_errors(char **matrix);
#endif
