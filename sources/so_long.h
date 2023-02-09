/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:40:59 by asousa-n          #+#    #+#             */
/*   Updated: 2023/02/08 13:39:57 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"

# define HEIGHT			64
# define WIDTH			64

# define WALL			'1'
# define FLOOR 			'0'
# define COLLECTIBLE 	'C'
# define PLAYER			'P'
# define MAP_EXIT 		'E'

# define W				119
# define A				97
# define S				115
# define D				100
# define UP  			65362
# define LEFT  			65361
# define RIGHT 			65363
# define DOWN	  		65364

# define ESC  			65307

# define P_FRONT		1
# define P_LEFT			2
# define P_RIGHT		3
# define P_BACK			4

# define WALL_XPM				"sprites/wall.xpm"
# define FLOOR_XPM				"sprites/floor.xpm"
# define EXIT_CLOSED_XPM		"sprites/exit-closed.xpm"
# define EXIT_OPEN_XPM			"sprites/exit-open.xpm"
# define COLLECTIBLE_XPM		"sprites/collectible.xpm"
# define PLAYER_FRONT_XPM		"sprites/player/front.xpm"
# define PLAYER_BACK_XPM		"sprites/player/back.xpm"
# define PLAYER_LEFT_XPM		"sprites/player/left.xpm"
# define PLAYER_RIGHT_XPM		"sprites/player/right.xpm"


typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int		rows;
	int		columns;
	int		collectible;
	int		exit;
	int		player;
	t_position	p_player;
	t_position	p_exit;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int		moves;
	int		player_sprite;
	t_map		map;
	t_image		wall;
	t_image		floor;
	t_image		collectible;
	t_image		exit_open;
	t_image		exit_closed;
	t_image		player_front;
	t_image		player_left;
	t_image		player_right;
	t_image		player_back;
}	t_game;

void	ft_verific_args(int argc, char **argv, t_game *game);
void	ft_verific_ber(char **argv, t_game *game);
void	ft_read_map(t_game *game, char *argv);
char	*ft_strjoin_free(char *s1, char *s2);
void	ft_init_var(t_game *game);
void	ft_verific_map(t_game *game);
void	ft_verific_walls(t_game *game);
void	ft_verific_format(t_game *game);
void	ft_count_sprites(t_game *game);
void	ft_verific_sprites(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);
int	ft_get_map(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_pos_player(t_game *game, int x, int y);
void	ft_get_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_string_put(t_game *game);
int		ft_play(int keysym, t_game *game);
void	ft_move_player(t_game *game, int n_x, int n_y, int player_sprite);
int		ft_win(t_game *game);
int		ft_close(t_game *game);
void	ft_free_map(char **map);
void	ft_free_all_allocated_memory(t_game *game);
void	ft_destroy_images(t_game *game);
int		ft_handler_error(char *msg, t_game *game);
void	ft_verific_path(t_game *game);


#endif
