/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:48:15 by falakus           #+#    #+#             */
/*   Updated: 2025/03/27 18:55:51 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

# define GREEN "\033[0;32m"
# define RESET "\033[0m"
# define RED    "\033[0;31m"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*ground;
	void	*wall;
	void	*coin;
	void	*exit;
}			t_mlx;

typedef struct s_map
{
	char	**map;
	char	**copy_map;
	char	*map_name;

	int		map_width;
	int		map_height;
	int		fd;
	int		player;
	int		coins;
	int		exit;
	int		p_xloc;
	int		p_yloc;
	int		e_xloc;
	int		e_yloc;
	int		moves;
	t_mlx	*mlx;
}			t_game;

void	map_copy(t_game *game);
void	map_array(t_game *game);
char	*check_map_name(t_game *game, char *av);
void	free_items2(t_game *game);
void	free_items(t_game *game);
void	print_error(char *str, t_game *game);
void	put_images(t_game *game, int i, int j);
void	make_window(t_game *game);
void	is_rectengular(t_game *game);
void	character_check(t_game *game);
void	map_control(t_game *game);
void	location(t_game *game);
void	flood_fill_test(t_game *game, int p_xloc, int p_yloc);
void	is_everywhere_reachable(t_game *game);
int		input_handler(int code, t_game *game);
int		close_window(t_game *game);
void	game_won(t_game *game);
#endif