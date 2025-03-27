/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:03:43 by falakus           #+#    #+#             */
/*   Updated: 2025/03/25 15:48:38 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectengular(t_game *game)
{
	int	i;

	i = 0;
	game->map_width = (int)ft_strlen(game->map[0]);
	while (i < game->map_height -1)
	{
		if ((int)ft_strlen(game->map[i]) != game->map_width)
			print_error(RED"Map is not rectengular!" RESET, game);
		i++;
	}
	if ((int)ft_strlen(game->map[game->map_height -1]) + 1 != game->map_width)
		print_error(RED"Map is not rectengular!"RESET, game);
}

static void	are_walls_just_one(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width - 1)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			print_error(RED"Walls are not just 1!"RESET, game);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 2] != '1')
			print_error(RED"Walls are not just 1!"RESET, game);
		i++;
	}
}

void	character_check(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0'
			&& game->map[i][j] != 'P' && game->map[i][j] != 'E'
			&& game->map[i][j] != 'C' && game->map[i][j] != '\n')
				print_error (RED"Invalid characters!"RESET, game);
			if (game->map [i][j] == 'P')
				game->player++;
			if (game->map[i][j] == 'E')
				game->exit++;
			if (game->map[i][j] == 'C')
				game->coins++;
			j++;
		}
	}
	if (game->player != 1 || game->exit != 1 || game->coins == 0)
		print_error (RED"The map must contain one player,one exit,"
			"and at least one coin!"RESET, game);
}

void	map_control(t_game *game)
{
	is_rectengular(game);
	are_walls_just_one(game);
	character_check(game);
}
