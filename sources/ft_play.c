#include "so_long.h"


void	ft_move_player(t_game *game, int n_y, int n_x, int player_sprite)
{
	int	l_x;
	int	l_y;
	
	game->player_sprite = player_sprite;
	l_x = game->map.p_player.x;
	l_y = game->map.p_player.y;
	if (game->map.full[n_y][n_x] == MAP_EXIT && game->map.collectible == 0)
		ft_victory(game);
	else if ((game->map.full[n_y][n_x] == FLOOR) || (game->map.full[n_y][n_x] == COLLECTIBLE))
	{
		game->map.full[l_y][l_x] = FLOOR;
		if (game->map.full[n_y][n_x] == COLLECTIBLE)
			game->map.collectible--;
		game->map.p_player.x = n_x;
		game->map.p_player.y = n_y;
		game->map.full[n_y][n_x] = PLAYER;
		game->moves++;
		ft_get_map(game);
	}
}

int	ft_play(int keysym, t_game *game)
{
	if (keysym == DOWN || keysym == S)
		ft_move_player(game, game->map.p_player.y + 1, game->map.p_player.x, P_FRONT);
	if (keysym == UP || keysym == W)
		ft_move_player(game, game->map.p_player.y - 1, game->map.p_player.x, P_BACK);
	if (keysym == LEFT || keysym == A)
		ft_move_player(game, game->map.p_player.y, game->map.p_player.x - 1, P_LEFT);
	if (keysym == RIGHT || keysym == D)
		ft_move_player(game, game->map.p_player.y, game->map.p_player.x + 1, P_RIGHT);
	if (keysym == ESC)
		ft_close_game(game);
	return (0);
}
