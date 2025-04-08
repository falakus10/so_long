/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:10:08 by falakus           #+#    #+#             */
/*   Updated: 2025/04/07 17:08:49 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	location(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == 'P')
			{
				game->p_yloc = i;
				game->p_xloc = j;
			}
			if (game->map[i][j] == 'E')
			{
				game->e_xloc = j;
				game->e_yloc = i;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill_test(t_game *game, int p_xloc, int p_yloc)
{
	if (game->copy_map[p_yloc][p_xloc] == '1' ||
game->copy_map[p_yloc][p_xloc] == 'F' || game->copy_map[p_yloc][p_xloc] == 'E')
		return ;
	game->copy_map[p_yloc][p_xloc] = 'F';
	flood_fill_test(game, p_xloc, p_yloc + 1);
	flood_fill_test(game, p_xloc, p_yloc - 1);
	flood_fill_test(game, p_xloc + 1, p_yloc);
	flood_fill_test(game, p_xloc - 1, p_yloc);
}

void	is_everywhere_reachable(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width - 1)
		{
			if (game->copy_map[i][j] == 'C')
				print_error(RED"Unreachable items on the map!\n"RESET, game);
			if (game->copy_map[i][j] == 'E')
			{
				if (game->copy_map[i][j + 1] != 'F' &&
					game->copy_map[i][j - 1] != 'F' &&
					game->copy_map[i + 1][j] != 'F' &&
					game->copy_map[i - 1][j] != 'F')
					print_error(RED"Unreachable Exit!\n"RESET, game);
			}
			j++;
		}
		i++;
	}
}
