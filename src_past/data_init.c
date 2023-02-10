#include "./../include/so_long.h"


/*캐릭터의 이미지 파일 구조체에 저장하고, 다양한 정보를 초기화한다.*/
void    ft_init(t_data *data, t_data *map)
{
	int		img_width;
    int		img_height;
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
	{
		ft_printf("img memory isn't allocated!");
		exit(EXIT_FAILURE);
	}
    data->img->player_up = mlx_xpm_file_to_image(data->mlx, 
				"./../img/mario_front.xpm", &img_width, &img_height);
    data->img->player_down = mlx_xpm_file_to_image(data->mlx, 
				"./../img/mario_back.xpm", &img_width, &img_height);
    data->img->player_left = mlx_xpm_file_to_image(data->mlx, 
				"./../img/mario_left.xpm", &img_width, &img_height);
    data->img->player_right = mlx_xpm_file_to_image(data->mlx, 
				"./../img/mario_right.xpm", &img_width, &img_height);
    data->img->background = mlx_xpm_file_to_image(data->mlx, 
				"./../img/grass.xpm", &img_width, &img_height);
	data->counter = 0;
	data->collected = 0;
}