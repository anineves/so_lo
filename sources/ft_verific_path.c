#include "so_long.h"
# include <stdbool.h>

static char	**copy_map(t_game *game)
{
	int		i;
	char	**copy;

	i = 0;
	copy = ft_calloc((game->map.rows + 1), sizeof(char *));
	if (!copy)
	{
		ft_free_map(copy);
		ft_handler_error("Invalid map", game);
	}
	while (i < game->map.rows)
	{
		copy[i] = ft_strdup(game->map.full[i]);
		if (!copy[i])
		{
			ft_free_map(copy);
			ft_handler_error("Invalid map", game);
		}
		i += 1;
	}
	return (copy);
}

static bool	flood_fill(t_map *map, t_position cur, char **map_c)
{
	static int		collectibles = 0;
	static bool		exit = false;

	if (map_c[cur.y][cur.x] == WALL)
		return (false);
	else if (map_c[cur.y][cur.x] == COLLECTIBLE)
		collectibles += 1;
	else if (map_c[cur.y][cur.x] == MAP_EXIT)
		exit = true;
	map_c[cur.y][cur.x] = WALL;
	flood_fill(map, (t_position){cur.x + 1, cur.y}, map_c);
	flood_fill(map, (t_position){cur.x - 1, cur.y}, map_c);
	flood_fill(map, (t_position){cur.x, cur.y + 1}, map_c);
	flood_fill(map, (t_position){cur.x, cur.y - 1}, map_c);
	return (collectibles == map->collectible && exit);
}

void	ft_verific_path(t_game *game)
{
	char	**map_c;

	map_c = copy_map(game);
	if (!flood_fill(&game->map, game->map.p_player, map_c))
		ft_handler_error("There is no valid path", game);
	ft_free_map(map_c);
	
}
