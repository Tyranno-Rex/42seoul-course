#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
#include "./../get_next_line/get_next_line.h"
#include "./../ft_printf/ft_printf.h"
#include "./../libft/libft.h"

# define IMG_W 32
# define IMG_H 32
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1


typedef struct s_map
{
	int character;
	int	star;
	int exit;
} t_map;

typedef struct s_gameinfo
{
	char	**map;
	int		map_w;
	int		map_h;
	int		wh;

	void	*mlx_p;
	void	*mlx_w;

	void	*wall;
	void	*space;
	void	*player;
	void	*collec;
	void	*exit;

	int		px;
	int		py;
	char	player_side;
	int		moves_counter;
	int		nb_collec;
}	t_gameinfo;

/*기존 함수*/



#endif
