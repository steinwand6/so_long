#include "../include/so_long.h"

int	check_status(int status, char *message)
{
	if (status != -1)
		return (status);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(status);
}

void	free_map(char **map, char *err_msg)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	if (err_msg)
		check_status(-1, err_msg);
}

int	quit_game(t_gameinfo *info)
{
	mlx_destroy_image(info->mlx_p, info->tile);
	mlx_destroy_image(info->mlx_p, info->player_img);
	mlx_destroy_image(info->mlx_p, info->goal);
	mlx_destroy_image(info->mlx_p, info->collection);
	mlx_destroy_image(info->mlx_p, info->wall);
	mlx_destroy_window(info->mlx_p, info->window_p);
	mlx_destroy_display(info->mlx_p);
	free(info->mlx_p);
	free_map(info->map, 0);
	exit (0);
}

int	init_gameinfo(t_gameinfo *info)
{
	int	size;

	size = TILE_SIZE;
	info->move_count = 0;
	info->mlx_p = mlx_init();
	if (!info->mlx_p)
		return (-1);
	info->window_p = mlx_new_window(info->mlx_p, info->x * size,
			info->y * size, "so_long");
	if (!info->window_p)
		return (-1);
	info->tile = mlx_xpm_file_to_image(info->mlx_p, TILE, &size, &size);
	info->wall = mlx_xpm_file_to_image(info->mlx_p, WALL, &size, &size);
	info->player_img = mlx_xpm_file_to_image(info->mlx_p,
			PLAYER, &size, &size);
	info->collection = mlx_xpm_file_to_image(info->mlx_p, COLLECT,
			&size, &size);
	info->goal = mlx_xpm_file_to_image(info->mlx_p, EXIT, &size, &size);
	if (!info->tile || !info->wall || !info->player_img
		|| !info->collection || !info->goal)
		return (-1);
	return (0);
}
