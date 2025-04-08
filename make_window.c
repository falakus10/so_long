/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:16:56 by falakus           #+#    #+#             */
/*   Updated: 2025/04/07 17:13:53 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images(t_game *game, int i, int j)
{
	while (i < game->map_height)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
					game->mlx->wall, j * 64, i * 64);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
					game->mlx->ground, j * 64, i * 64);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
					game->mlx->player, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
					game->mlx->coin, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->win_ptr,
					game->mlx->exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

static void	control_images(t_game *game)
{
	if (game->mlx->player == NULL || game->mlx->wall == NULL
		|| game->mlx->ground == NULL || game->mlx->coin == NULL
		|| game->mlx->exit == NULL)
		print_error(RED"Missing image file!"RESET, game);
}

static void	add_images(t_game *game)
{
	int	width;
	int	height;
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->mlx->player = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
			"images/player.xpm", &width, &height);
	game->mlx->ground = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
			"images/ground.xpm", &width, &height);
	game->mlx->wall = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
			"images/wall.xpm", &width, &height);
	game->mlx->coin = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
			"images/coin.xpm", &width, &height);
	game->mlx->exit = mlx_xpm_file_to_image(game->mlx->mlx_ptr,
			"images/exit.xpm", &width, &height);
	control_images(game);
	put_images(game, i, j);
}

void	make_window(t_game *game)
{
	game->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (game->mlx == NULL)
		print_error(RED"Memory error !"RESET, game);
	game->mlx->mlx_ptr = NULL;
	game->mlx->win_ptr = NULL;
	game->mlx->mlx_ptr = mlx_init();
	game->mlx->win_ptr = mlx_new_window(game->mlx->mlx_ptr,
			(game->map_width - 1) * 64, game->map_height * 64, "so_long");
	add_images(game);
}
