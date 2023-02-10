/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:39:54 by asousa-n          #+#    #+#             */
/*   Updated: 2023/02/08 13:24:24 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verific_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if ( map[0] == '\n')
	{
		free(map);
		ft_handler_error1("Invalid map.\
The map have an empty line", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_handler_error1("Invalid map. \
The map have an empty line", game);
		}
		i++;
	}
}

void	ft_read_map(t_game *game, char *map_file)
{
	char	*map_t;
	char	*line;
	int		read;
	
	read = open(map_file, O_RDONLY);
	if (read == -1)
		ft_handler_error1("The map unable to open", game);
	map_t = ft_calloc(sizeof(char), 1);
	game->map.rows = 0;
	while (1)
	{
		line = get_next_line(read);
		if (line == NULL)
			break ;
		map_t = ft_strjoin_free(map_t, line);
		free(line);
		game->map.rows++;
	}
	close(read);
	ft_verific_line(map_t, game);
	game->map.full = ft_split(map_t, '\n');
	free(map_t);
}

void	ft_init_var(t_game *game)
{
	game->map.collectible = 0;
	game->map.exit = 0;
	game->map.player = 0;
	game->moves = 0;
	game->player_sprite = P_FRONT;
	game->map.columns = ft_strlen(game->map.full[0]);
}
