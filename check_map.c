/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falakus <falakus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:55:36 by falakus           #+#    #+#             */
/*   Updated: 2025/03/22 16:59:39 by falakus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_copy(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	game->fd = open(game->map_name, O_RDONLY);
	line = get_next_line(game->fd);
	game->copy_map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (game->copy_map == NULL)
		print_error(RED "Memory error!\n"RESET, game);
	while (line != NULL)
	{
		game->copy_map[i] = line;
		line = get_next_line(game->fd);
		i++;
	}
	free (line);
	game->copy_map[i] = NULL;
	close(game->fd);
}

static void	ft_height(t_game *game)
{
	char	*line;

	game->fd = open(game->map_name, O_RDONLY);
	line = get_next_line(game->fd);
	while (line)
	{
		game->map_height++;
		free(line);
		line = get_next_line(game->fd);
	}
	free (line);
	close(game->fd);
}

void	map_array(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	ft_height(game);
	game->fd = open(game->map_name, O_RDONLY);
	line = get_next_line(game->fd);
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	if (game->map == NULL)
		print_error(RED"Memory error!\n"RESET, game);
	while (line != NULL)
	{
		game->map[i] = line;
		line = get_next_line(game->fd);
		i++;
	}
	free (line);
	game->map[i] = NULL;
	close(game->fd);
	map_copy(game);
}

char	*check_map_name(t_game *game, char *av)
{
	int		lenght;
	char	*line;

	game->fd = open(av, O_RDONLY);
	if (game->fd == -1)
		print_error(RED"No such file or directory!" RESET, game);
	lenght = ft_strlen(av);
	if (av[lenght - 1] != 'r' || av[lenght - 2] != 'e' || av[lenght - 3] != 'b'
		|| av[lenght - 4] != '.')
	{
		print_error(RED "File extension must be .ber!" RESET, game);
	}
	line = get_next_line (game->fd);
	if (line == NULL)
	{
		ft_printf ("Empty file!\n");
		free(game);
		exit (0);
	}
	free(line);
	close(game->fd);
	return (av);
}
