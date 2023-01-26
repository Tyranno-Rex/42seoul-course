#include <mlx.h>


int main()
{
	void *mlx;
	void *win;
	void *img_1;
	void *img_2;
	void *img_3;
	void *img_4;
	void *img_5;
	void *img_6;
	void *img_7;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 500, "my_mlx");
	

    // xpm 이미지 불러오기
    img_1 = mlx_xpm_file_to_image(mlx, "./img/mario_front.xpm", &img_width, &img_height);
	img_2 = mlx_xpm_file_to_image(mlx, "./img/mario_back.xpm", &img_width, &img_height);
	img_3 = mlx_xpm_file_to_image(mlx, "./img/mario_left.xpm", &img_width, &img_height);
	img_4 = mlx_xpm_file_to_image(mlx, "./img/mario_right.xpm", &img_width, &img_height);
	img_5 = mlx_xpm_file_to_image(mlx, "./img/chimney.xpm", &img_width, &img_height);
	img_6 = mlx_xpm_file_to_image(mlx, "./img/star.xpm", &img_width, &img_height);
	img_7 = mlx_xpm_file_to_image(mlx, "./img/grass.xpm", &img_width, &img_height);


    // xpm 이미지 띄우기
	mlx_put_image_to_window(mlx, win, img_1, 0, 0);
	mlx_put_image_to_window(mlx, win, img_2, 100, 0);
	mlx_put_image_to_window(mlx, win, img_3, 200, 0);
	mlx_put_image_to_window(mlx, win, img_4, 300, 0);
	mlx_put_image_to_window(mlx, win, img_5, 400, 0);
	mlx_put_image_to_window(mlx, win, img_6, 500, 0);
	mlx_put_image_to_window(mlx, win, img_7, 600, 0);
	mlx_loop(mlx);
	return (0);
}