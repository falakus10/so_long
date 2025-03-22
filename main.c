/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:48:11 by falakus           #+#    #+#             */
/*   Updated: 2025/03/22 16:57:05 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_won(t_game *game)
{
	free_items2(game);
	free_items(game);
	ft_printf(GREEN"\n\t\t\t\tCONGRATULATIONS, YOU ARE VICTORIOUS!\t\t\t\t\n"RESET);
	exit (0);
}

static void	stack_fill(t_game *game)
{
	game->map = NULL;
	game->mlx = NULL;
	game->e_xloc = 0;
	game->e_yloc = 0;
	game->p_xloc = 0;
	game->p_yloc = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->player = 0;
	game->exit = 0;
	game->coins = 0;
	game->moves = 1;
}

int	close_window(t_game *game)
{
	free_items2(game);
	free_items(game);
	ft_printf("Window closed\n");
	exit(0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
	{
		print_error(RED"Memory Error!"RESET, game);
	}
	stack_fill(game);
	if (ac != 2)
		print_error(RED"Please insert a map!"RESET, game);
	game->map_name = check_map_name(game, av[1]);
	map_array(game);
	map_control(game);
	location(game);
	flood_fill_test(game, game->p_xloc, game->p_yloc);
	is_everywhere_reachable(game);
	make_window(game);
	mlx_key_hook(game->mlx->win_ptr, input_handler, game);
	mlx_hook(game->mlx->win_ptr, 17, 0, close_window, game);
	mlx_loop(game->mlx->mlx_ptr);
}
