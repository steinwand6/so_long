#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define TILE_SIZE 50
# define TILE "./textures/tile.xpm"
# define WALL "./textures/block.xpm"
# define PLAYER "./textures/kairu_w.xpm"
# define COLLECT "./textures/iruka_w.xpm"
# define EXIT "./textures/exit_w.xpm"

typedef struct s_gameinfo
{
	char	**map;
	int		y;
	int		x;
	int		p_x;
	int		p_y;
	int		move_count;
	int		fpl;
	void	*tile;
	void	*wall;
	void	*player_img;
	void	*collection;
	int		num_of_clct;
	void	*goal;
	void	*mlx_p;
	void	*window_p;
}				t_gameinfo;

int		check_status(int status, char *message);
char	**read_map(char *path);
int		check_and_fix_map(t_gameinfo *info);
void	free_map(char **map, char *err_msg);
int		quit_game(t_gameinfo *info);
int		init_gameinfo(t_gameinfo *info);

#endif
