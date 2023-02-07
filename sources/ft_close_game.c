#include "so_long.h"


int	ft_victory(t_game *game)
{
	ft_printf("\n			Movements: %d\n", ++game->moves);
	ft_free_all_allocated_memory(game);
	ft_printf("CONGRATULATION, YOU WIN!!!! \n");
	exit (EXIT_FAILURE);
}

int	ft_close_game(t_game *game)
{
	ft_printf("Movements: %d\n", game->moves);
	ft_free_all_allocated_memory(game);
	ft_printf("CLOSED\n");
	exit (EXIT_FAILURE);
}
