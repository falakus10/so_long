/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:20:46 by falakus           #+#    #+#             */
/*   Updated: 2025/03/27 19:00:08 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_left(t_game *game)
{
	if (game->map[game->p_yloc][game->p_xloc - 1] != '1')
	{
		if (game->map[game->p_yloc][game->p_xloc - 1] == 'E' && game->coins > 0)
			return ;
		ft_printf("Move: %d\n", game->moves++);
		if (game->map[game->p_yloc][game->p_xloc - 1] == 'C')
			game->coins--;
		if (game->map[game->p_yloc][game->p_xloc - 1] == 'E' &&
		game->coins == 0)
			game_won(game);
		else
		{
			game->map[game->p_yloc][game->p_xloc] = '0';
			game->p_xloc--;
			game->map[game->p_yloc][game->p_xloc] = 'P';
		}
	}
}

static void	move_right(t_game *game)
{
	if (game->map[game->p_yloc][game->p_xloc + 1] != '1')
	{
		if (game->map[game->p_yloc][game->p_xloc + 1] == 'E' && game->coins > 0)
			return ;
		ft_printf("Move: %d\n", game->moves++);
		if (game->map[game->p_yloc][game->p_xloc + 1] == 'C')
			game->coins--;
		if (game->map[game->p_yloc][game->p_xloc + 1] == 'E' &&
		game->coins == 0)
			game_won(game);
		else
		{
			game->map[game->p_yloc][game->p_xloc] = '0';
			game->p_xloc++;
			game->map[game->p_yloc][game->p_xloc] = 'P';
		}
	}
}

static void	move_down(t_game *game)
{
	if (game->map[game->p_yloc + 1][game->p_xloc] != '1')
	{
		if (game->map[game->p_yloc + 1][game->p_xloc] == 'E' && game->coins > 0)
			return ;
		ft_printf("Move: %d\n", game->moves++);
		if (game->map[game->p_yloc + 1][game->p_xloc] == 'C')
			game->coins--;
		if (game->map[game->p_yloc + 1][game->p_xloc] == 'E' &&
		game->coins == 0)
			game_won(game);
		else
		{
			game->map[game->p_yloc][game->p_xloc] = '0';
			game->p_yloc++;
			game->map[game->p_yloc][game->p_xloc] = 'P';
		}
	}
}

static void	move_up(t_game *game)
{
	if (game->map[game->p_yloc - 1][game->p_xloc] != '1')
	{
		if (game->map[game->p_yloc - 1][game->p_xloc] == 'E' && game->coins > 0)
			return ;
		ft_printf("Move: %d\n", game->moves++);
		if (game->map[game->p_yloc - 1][game->p_xloc] == 'C')
			game->coins--;
		if (game->map[game->p_yloc - 1][game->p_xloc] == 'E' &&
		game->coins == 0)
			game_won(game);
		else
		{
			game->map[game->p_yloc][game->p_xloc] = '0';
			game->p_yloc--;
			game->map[game->p_yloc][game->p_xloc] = 'P';
		}
	}
}

int	input_handler(int code, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (code == 65307)
		close_window(game);
	if (code == 97 || code == 65361)
		move_left(game);
	if (code == 100 || code == 65363)
		move_right(game);
	if (code == 115 || code == 65364)
		move_down(game);
	if (code == 119 || code == 65362)
		move_up(game);
	put_images(game, i, j);
	return (0);
}
