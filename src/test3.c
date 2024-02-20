#include "fdf.h"

// int code_rgb(int red, int green, int blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }
//ouvrir la connection , ouvrir la fenetre , donner les coordonnees du pixel 
// et sa couleur en hexa (0x). faire un rectangle dynamique

int	handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_connect, data->mlx_window);
        data->mlx_window = NULL;
    }
    return (0);
}

int render_rect(t_data *data, t_img rect)
{
	int i;
	int j;

	if (data->mlx_window == NULL)
		return (1);
	i = rect.ypos;
	while (i < rect.ypos + rect.height)
	{
		j = rect.xpos;
		while (j < rect.xpos + rect.width)
			mlx_pixel_put(data->mlx_connect, data->mlx_window, j++, i, 0xFF0000);
		++i;
	}
	return (0);
}

int	render(t_data *data)
{
    t_img img;
	
	img.ypos = 0;
	img.xpos = 0;
	img.height = 200;
	img.width = 300;
	render_rect(data, img);
    return (0);
}

int main()
{
	//t_img img;
	t_data data;
	data.mlx_connect = mlx_init(); 
	if (!data.mlx_connect)
		return (1);
	data.winheight = 400;
	data.winwidth = 600;	
	data.mlx_window = mlx_new_window(data.mlx_connect, 
									data.winwidth, 
									data.winheight, 
									"first window"); 
	if (!data.mlx_window)
	{
		free(data.mlx_window);
		return (1);
	}	
	mlx_loop_hook(data.mlx_connect, &render, &data);
	mlx_hook(data.mlx_window, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_string_put(data.mlx_connect, data.mlx_window, data.winwidth * 0.8, data.winheight * 0.95, 0xFF0000, "first test");
	mlx_loop(data.mlx_connect);
	//mlx_destroy_window(data.mlx_connect, data.mlx_window);
	mlx_destroy_display(data.mlx_connect);
	free(data.mlx_connect);
	return (0);
}