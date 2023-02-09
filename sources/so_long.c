#include "so_long.h"

void	ft_verific_args(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		ft_handler_error("Invald number of arguments", game);
	if (*argv[1] == '\0')
		ft_handler_error("Please choose a map", game);
}

void	ft_verific_ber(char **argv, t_game *game)
{
	int	len_map;

	len_map = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len_map - 4], ".ber", 4))
		ft_handler_error("The map must end in .ber", game);
}

int main(int argc, char **argv)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	
	ft_verific_args(argc, argv, game);
	ft_verific_ber(argv, game);
	ft_read_map(game, argv[1]);
	ft_init_var(game);
	ft_verific_map(game);
	ft_verific_path(game);
	ft_init_mlx(game);
	ft_init_sprites(game);
	ft_get_map(game);
	mlx_hook(game->win_ptr, 02, (1L<<0), ft_play, game);
	mlx_hook(game->win_ptr, 17, (1L<<2), ft_close, game);
	mlx_hook(game->win_ptr, 12, (1L<<15), ft_get_map, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all_allocated_memory(game);
	


}
