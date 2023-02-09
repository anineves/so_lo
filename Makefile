CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11
LIBFT = ./libft/libft.a
RM = rm -rf
NAME = so_long

SRCS_DIR		= ./sources/

SRCS 			= $(addprefix $(SRCS_DIR),\
			so_long.c		\
			ft_free_memory.c	\
			ft_get_map.c		\
			ft_init_game.c		\
			ft_init_mlx.c		\
			ft_play.c		\
			ft_utils.c		\
			ft_verific_map.c		\
			ft_verific_path.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE)  -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all

