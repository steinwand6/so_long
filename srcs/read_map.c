#include "../include/so_long.h"

char	**read_map(char *path)
{
	char	**map;
	char	*line;
	int		fd;
	int		result;
	int		i;

	fd = check_status(open(path, O_RDONLY), "File open error.");
	i = 0;
	while (check_status(get_next_line(fd, &line), "While reading.") > 0)
	{
		free(line);
		i++;
	}
	free(line);
	map = malloc(sizeof(char *) * (i + 2));
	check_status(close(fd), "File close error.");
	fd = check_status(open(path, O_RDONLY), "File open error.");
	i = 0;
	result = 1;
	while (result > 0)
		result = check_status(get_next_line(fd, &map[i++]), "While reading.");
	map[i] = NULL;
	check_status(close(fd), "File close error.");
	return (map);
}

int	count_y_and_delete_empty(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	if (i == 1)
		free_map(map, "Map file is empty.");
	while (ft_strlen(map[--i]) == 0)
	{
		free(map[i]);
		map[i] = NULL;
	}
	i++;
	if (i > INT_MAX || ft_strlen(map[i - 1]) > INT_MAX)
		free_map(map, "Map file is too big.");
	return (i);
}

int	check_no_hole(char *map, int top_or_btm)
{
	int	x;

	x = 0;
	if (top_or_btm)
	{
		while (map[x])
		{
			if (map[x++] != '1')
				return (-1);
		}
	}
	else
	{
		while (map[x])
		{
			if (x == 0 || map[x + 1] == '\0')
			{
				if (map[x] != '1')
					return (-1);
			}
			x++;
		}
	}
	return (0);
}

int	check_elements_in_map(t_gameinfo *info)
{
	int	x;
	int	y;
	int	cnt_pe[2];

	cnt_pe[0] = 0;
	cnt_pe[1] = 0;
	y = 0;
	while (y < info->y)
	{
		x = 0;
		while (x < info->x)
		{
			if (info->map[y][x] == 'P')
			{
				info->p_x = x;
				info->p_y = y;
			}
			cnt_pe[0] += info->map[y][x] == 'P';
			cnt_pe[1] += info->map[y][x] == 'E';
			info->num_of_clct += info->map[y][x] == 'C';
			x++;
		}
		y++;
	}
	return ((cnt_pe[0] != 1 || cnt_pe[1] == 0 || !info->num_of_clct) * -1);
}

int	check_and_fix_map(t_gameinfo *info)
{
	int	y;

	y = 0;
	info->y = check_status(count_y_and_delete_empty(info->map),
			"Map file is wrong.");
	info->x = ft_strlen(info->map[y]);
	info->num_of_clct = 0;
	if (check_elements_in_map(info) == -1)
		free_map(info->map, "Invalid number of elements.");
	while (y < info->y)
	{
		if ((int)ft_strlen(info->map[y]) != info->x)
			free_map(info->map, "Lines are not equal in length.");
		if ((y == 0 || y == info->y - 1)
			&& check_no_hole(info->map[y], 1) == -1)
			free_map(info->map, "The map is not covered by a wall.");
		else if (check_no_hole(info->map[y], 0) == -1)
			free_map(info->map, "The map is not covered by a wall.");
		y++;
	}
	return (0);
}
