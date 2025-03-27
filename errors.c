/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:23:42 by falakus           #+#    #+#             */
/*   Updated: 2025/03/28 02:20:09 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_items2(t_game *game)
{
	mlx_destroy_image(game->mlx->mlx_ptr, game->mlx->player);
	mlx_destroy_image(game->mlx->mlx_ptr, game->mlx->coin);
	mlx_destroy_image(game->mlx->mlx_ptr, game->mlx->wall);
	mlx_destroy_image(game->mlx->mlx_ptr, game->mlx->ground);
	mlx_destroy_image(game->mlx->mlx_ptr, game->mlx->exit);
	mlx_destroy_window(game->mlx->mlx_ptr, game->mlx->win_ptr);
	mlx_destroy_display(game->mlx->mlx_ptr);
	free(game->mlx->mlx_ptr);
	free(game->mlx);
}

void	free_items(t_game *game)
{
	int	i;

	i = 0;
	if (game->map != NULL)
	{
		while (i < game->map_height)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	i = 0;
	if (game->copy_map != NULL)
	{
		while (i < game->map_height)
		{
			free(game->copy_map[i]);
			i++;
		}
		free (game->copy_map);
	}
	free (game);
}

void	print_error(char *str, t_game *game)
{
	ft_printf("%s", str);
	if (game == NULL)
		exit (0);
	else if (game->map == NULL)
	{
		free(game);
		exit(0);
	}
	else
		free_items(game);
	exit (0);
}
