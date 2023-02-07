#include "so_long.h"

void	ft_read_map(t_game *game, char *map_file)
{
	char	*map_t;
	char	*line;
	int		read;
	
	read = open(map_file, O_RDONLY);
	if (read == -1)
		ft_handler_error("The map unable to open", game);
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
	game->map.full = ft_split(map_t, '\n');
	game->map_alloc = true;
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

