#include "so_long.h"


char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*newstr;
	int	i;
	int	j;

	if (!s1)
	{
		return (NULL);
	}
	newstr = (char *)malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		newstr[j++] = s1[i];
	i = -1;
	while (s2[++i])
		newstr[j++] = s2[i];
	newstr[j] = '\0';
	free(s1);
	return (newstr);
}

int	ft_handler_error(char *msg, t_game *game)
{
	if (game->map.full)
		ft_free_map(game->map.full);
	free(game);
	ft_printf("Error\n %s", msg);
	exit (EXIT_FAILURE);
}
