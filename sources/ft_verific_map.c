/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verific_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:40:27 by asousa-n          #+#    #+#             */
/*   Updated: 2023/02/08 10:40:50 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verific_sprites(t_game *game)
{
	if (game->map.collectible == 0)
		ft_handler_error("The map to be valid must have at least one Collectibles", game);
	else if (game->map.exit != 1)
		ft_handler_error("The map to be valid must have one Exit", game);
	else if (game->map.player != 1)
		ft_handler_error("The map to be valid must have ONE Player", game);
}

void	ft_count_sprites(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("01CEP", game->map.full[y][x]))
				ft_handler_error("Invalid Map. Not expected map character.", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.player++;
				game->map.p_player.x = x;
				game->map.p_player.y = y;
			}
			else if (game->map.full[y][x] == COLLECTIBLE)
				game->map.collectible++;
			else if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_verific_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_handler_error("The map to be valid must be surrounded by walls", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_handler_error("The map to be valid must be surrounded by walls", game);
		i++;
	}
	
	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_handler_error("The map to be valid must be surrounded by walls", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
			ft_handler_error("The map to be valid must be surrounded by walls", game);
		i++;
	}
}

void	ft_verific_format(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if ((int) ft_strlen(game->map.full[i]) != game->map.columns)
			ft_handler_error("The map to be valid must be rectangular!", game);
		i++;
	}
}

void	ft_verific_map(t_game *game)
{
	ft_verific_format(game);
	ft_verific_walls(game);
	ft_count_sprites(game);
	ft_verific_sprites(game);
}
