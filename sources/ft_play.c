/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:40:09 by asousa-n          #+#    #+#             */
/*   Updated: 2023/02/08 13:41:14 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_win(t_game *game)
{
	ft_printf("Movements: %d\n", ++game->moves);
	ft_free_all_allocated_memory(game);
	ft_printf("CONGRATULATION, YOU WIN!!!! \n");
	exit (EXIT_FAILURE);
}

void	ft_move_player(t_game *game, int n_y, int n_x, int player_sprite)
{
	int	l_x;
	int	l_y;
	
	game->player_sprite = player_sprite;
	ft_printf("exit x %d y %d\n ", game->map.p_exit.y, game->map.p_exit.x);
	l_x = game->map.p_player.x;
	l_y = game->map.p_player.y;
	if (game->map.full[n_y][n_x] == MAP_EXIT && game->map.collectible == 0)
		ft_win(game);
	else if ((game->map.full[n_y][n_x] == FLOOR) || (game->map.full[n_y][n_x] == COLLECTIBLE) || (game->map.full[n_y][n_x] == MAP_EXIT))
	{
		game->map.full[l_y][l_x] = FLOOR;
		if (game->map.full[n_y][n_x] == COLLECTIBLE)
			game->map.collectible--;
		game->map.p_player.x = n_x;
		game->map.p_player.y = n_y;
		game->map.full[n_y][n_x] = PLAYER;
		if (game->map.full[game->map.p_exit.y][game->map.p_exit.x] != PLAYER)
			game->map.full[game->map.p_exit.y][game->map.p_exit.x] = MAP_EXIT;
		game->moves++;
		ft_printf("Moves: %d \n", game->moves);
		ft_get_map(game);
	}
}

int	ft_close(t_game *game)
{
	ft_printf("Movements: %d\n", game->moves);
	ft_free_all_allocated_memory(game);
	ft_printf("CLOSED\n");
	exit (EXIT_FAILURE);
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
		ft_close(game);
	return (0);
}
