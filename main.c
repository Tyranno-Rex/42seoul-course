#include <mlx.h>

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
    void *mlx; 
    void *mlx_win;
    void *img;
    t_data img_s; // 이미지 데이터 struct

    
    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 500, 500, "mlx window");
    // img_s.img = mlx_new_image(mlx, 1920, 1080);
    // img_s.addr = mlx_get_data_addr(img_s.img, &img_s.bits_per_pixel, 
    //                             &img_s.line_length, &img_s.endian);
    // my_mlx_pixel_put(&img_s, 5, 5, 0x00FF0000);
    // mlx_put_image_to_window(mlx, mlx_win, img_s.img, 0, 0);
    // mlx_loop(mlx);

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img_s.img = mlx_new_image(mlx, 1920, 1080);
	img_s.addr = mlx_get_data_addr(img_s.img, &img_s.bits_per_pixel, &img_s.line_length, &img_s.endian);
	my_mlx_pixel_put(&img_s, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img_s.img, 0, 0);
	mlx_loop(mlx);

    // 창 띄우기 
    // mlx = mlx_init();
    // mlx_win = mlx_new_window(mlx, 500, 500, "mlx window");
    // mlx_loop(mlx);
    
    // 이미지 띄우기   
    // mlx = mlx_init();
    // img = mlx_new_image(mlx, 1920, 1080);

    // 이미지 띄우기
    // mlx = mlx_init();
    // img_s.img = mlx_new_image(mlx, 1920, 1080);
    // img_s.addr = mlx_get_data_addr(img_s.img, &img_s.bits_per_pixel, &img_s.line_length, 
    //                             &img_s.endian);
    return (0);
}