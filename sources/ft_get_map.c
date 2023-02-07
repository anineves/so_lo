#include "so_long.h"


void	ft_string_put(t_game *game)
{
	char	*str;
	char	*moves;

	moves = ft_itoa(game->moves);
	str = ft_strjoin("Movements : ", moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 90, 0x00FF0000, str);
	free(moves);
	free(str);
}

void	ft_get_sprite(t_game *game, t_image sprite, int row, int col)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
	sprite.xpm_ptr, col * sprite.x, row * sprite.y);
}

void	ft_pos_player(t_game *game, int y, int x)
{
	if (game->player_sprite == P_FRONT)
		ft_get_sprite (game, game->player_front, y, x);
	if (game->player_sprite == P_LEFT)
		ft_get_sprite (game, game->player_left, y, x);
	if (game->player_sprite == P_RIGHT)
		ft_get_sprite (game, game->player_right, y, x);
	if (game->player_sprite == P_BACK)
		ft_get_sprite (game, game->player_back, y, x);
}

void	ft_identify_sprite(t_game *game, int y, int x)
{	
	char	parameter;

	parameter = game->map.full[y][x];
	if (parameter == WALL)
		ft_get_sprite (game, game->wall, y, x);
	else if (parameter == FLOOR)
		ft_get_sprite (game, game->floor, y, x);
	else if (parameter == COLLECTIBLE)
		ft_get_sprite (game, game->collectible, y, x);
	else if (parameter == MAP_EXIT)
	{
		if (game->map.collectible > 0)
			ft_get_sprite (game, game->exit_closed, y, x);
		else
			ft_get_sprite (game, game->exit_open, y, x);
	}
	else if (parameter == PLAYER)
		ft_pos_player (game, y, x);
}

int	ft_get_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_string_put(game);
	return (0);
}

