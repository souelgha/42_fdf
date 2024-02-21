#include "fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_connect, data->mlx_window);
        data->mlx_window = NULL;
    }
    return (0);
}

int	close_win(t_data *data)
{

    mlx_destroy_window(data->mlx_connect, data->mlx_window);
	data->mlx_window = NULL;
    return (0);
}

 int code_trgb(int t, int red, int green, int blue)
{
 	return (t << 24 | red << 16 | green << 8 | blue);
}

/*void color_rect(t_data *data, int color)
{
	int i;
	int j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 300)
			my_pixel_put(&data->img, ++j, i, color);
		++i;
	}
	
}*/
/*void color_rect(t_data *data, int color)
{
	my_pixel_put(&data->img, 150, 150, color);
}*/

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + ( x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->addr_pixel)) = color;
}

/*int f(int keysym, t_data *data)
{
	if (keysym == XK_r)
		color_rect(data, code_trgb(0, 255, 255, 0));
	else if (keysym == XK_g)
		color_rect(data, code_trgb(100, 0, 255, 0));
	else if (keysym == XK_b)
		color_rect(data, code_trgb(00, 0, 0, 255));
	mlx_put_image_to_window(data->mlx_connect, data->mlx_window, data->img.img_ptr, 0, 0);
	return (0);
}*/
