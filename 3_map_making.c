#include <stdio.h>  // printf()
#include <stdlib.h> // exit()
#include <mlx.h>

// 0 for an empty space,
// 1 for a wall,
// C for a collectible,
// E for a map exit,
// P for the player’s starting position.

void	map_read(char *filename, t_game *game)
{
	int  fd;
	char *line;

	// 파일을 열었을 때 fd값을 가져온다.
	fd = open("./map/1_map.ber", O_RDONLY);
	// 라인을 읽어 옴
	line = get_next_line(fd);
	game->hei = 0;
	game->wid = ft_strlen(line) - 1;
	game->str_line = ft_strdup_without_newline(line);
	free(line);
	while (line)
	{
		game->hei++;
		line = get_next_line(fd);
		if (line)
			game->str_line = ft_strjoin_without_newline(game->str_line, line);
	}
	close(fd);
	printf("%s\n", game->str_line);
}

void	setting_img(t_game game)
{
	int		hei;
	int		wid;

	hei = 0;
	while (hei < game.height)
	{
		wid = 0;
		while (wid < game.width)
		{
			if (game.str_line[hei * game.width + wid] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.img.wall, wid * 64, hei * 64);
			else if (game.str_line[hei * game.width + wid] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.img.chest, wid * 64, hei * 64);
			else if (game.str_line[hei * game.width + wid] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.img.chara, wid * 64, hei * 64);
			else if (game.str_line[hei * game.width + wid] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.img.rune, wid * 64, hei * 64);
			else
				mlx_put_image_to_window(game.mlx, game.win, game.img.land, wid * 64, hei * 64);
			wid++;
		}
		hei++;
	}
}

int main()
{
	
}