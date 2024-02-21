#include "fdf.h"

/***positionnement du pixel sur la window***/


int main()
{
	t_data data;
	t_img	img;

	int winheight;
	int	winwidth;
	int height;
	int	width;

	data.mlx_connect = mlx_init(); 
	if (!data.mlx_connect)
	{
		free(data.mlx_connect);
		return (1);
	}
		
	winheight = 500;
	winwidth = 800;	
	width = 400;
	height = 300;
	
	data.mlx_window = mlx_new_window(data.mlx_connect, winwidth, winheight, "first window"); 
	if (!data.mlx_window)
	{
		mlx_destroy_display(data.mlx_connect);
		free(data.mlx_window);
		return (1);
	}
	img.img_ptr =  mlx_new_image(data.mlx_connect, width, height);
	img.addr_pixel = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_len, &img.endian);
	my_pixel_put(&img, 200, 50, 0x00FF0000);
	printf("line_len=%d\nbpp=%d\nendian=%d\n", img.line_len, img.bits_per_pixel, img.endian);
	mlx_put_image_to_window(data.mlx_connect, data.mlx_window, img.img_ptr, 0, 0);
	//mlx_key_hook(data.mlx_window, f, &data);
	mlx_hook(data.mlx_window, 17, 1L<<5, close_win, &data);
	mlx_hook(data.mlx_window, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_string_put(data.mlx_connect, data.mlx_window, winwidth * 0.8, winheight * 0.95, 0xFF0000, "first test");
	mlx_loop(data.mlx_connect);
	mlx_destroy_display(data.mlx_connect);
	free(data.mlx_connect);
	return (0);
}