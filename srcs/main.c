#include "../include/so_long.h"

int	move(t_gameinfo *info, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = info->p_x + x;
	new_y = info->p_y + y;
	if (info->map[new_y][new_x] == '1')
		return (0);
	info->move_count += 1;
	printf("move count: %d\n", info->move_count);
	if (info->move_count == INT_MAX)
	{
		printf("reset move count.\n");
		info->move_count = 0;
	}
	return (1);
}

int	key_hook(int key, t_gameinfo *info)
{
	if (key == 119)
		info->p_y -= move(info, 0, -1);
	else if (key == 115)
		info->p_y += move(info, 0, 1);
	else if (key == 97)
		info->p_x -= move(info, -1, 0);
	else if (key == 100)
		info->p_x += move(info, 1, 0);
	else if (key == 65307)
		quit_game(info);
	if (info->map[info->p_y][info->p_x] == 'C')
	{
		info->map[info->p_y][info->p_x] = '0';
		info->num_of_clct -= 1;
	}
	if (info->map[info->p_y][info->p_x] == 'E' && !info->num_of_clct)
		quit_game(info);
	return (0);
}

void	put_image(t_gameinfo *info, int x, int y)
{
	int	size;

	size = TILE_SIZE;
	if (info->map[y][x] == '1')
		mlx_put_image_to_window(info->mlx_p, info->window_p,
			info->wall, x * size, y * size);
	else if (info->p_x == x && info->p_y == y)
		mlx_put_image_to_window(info->mlx_p, info->window_p,
			info->player_img, x * size, y * size);
	else if (info->map[y][x] == 'C')
		mlx_put_image_to_window(info->mlx_p, info->window_p,
			info->collection, x * size, y * size);
	else if (info->map[y][x] == 'E')
		mlx_put_image_to_window(info->mlx_p, info->window_p,
			info->goal, x * size, y * size);
	else
		mlx_put_image_to_window(info->mlx_p, info->window_p,
			info->tile, x * size, y * size);
}

int	main_loop(t_gameinfo *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->y)
	{
		x = 0;
		while (x < info->x)
		{
			put_image(info, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_gameinfo	info;
	char		*ptr;

	ptr = ft_strrchr(argv[1], '.');
	if (!ptr || ptr[1] != 'b' || ptr[2] != 'e' || ptr[3] != 'r' || ptr[4])
		check_status(-1, "Invalid map extention.");
	if (argc == 2)
	{
		info.map = read_map(argv[1]);
		check_and_fix_map(&info);
		if (info.map == NULL)
			exit(1);
		check_status(init_gameinfo(&info), "Fail init gameinfo");
		mlx_hook(info.window_p, 17, 1L << 17, quit_game, &info);
		mlx_key_hook(info.window_p, key_hook, &info);
		mlx_loop_hook(info.mlx_p, &main_loop, &info);
		mlx_loop(info.mlx_p);
	}
	else
		check_status(-1, "Invalid Arguments.");
	return (0);
}
