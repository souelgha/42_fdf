#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdint.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <stdio.h>

typedef struct s_img
{
	void	*mlx_connect;
	void	*mlx_window;
	int		height;
	int 	width;
	int 	xpos;
	int		ypos;
	int		color;
}	t_img;

// int code_rgb(int red, int green, int blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }
//ouvrir la connection , ouvrir la fenetre , donner les coordonnees du pixel 
// et sa couleur en hexa (0x). faire un rectangle dynamique

int	handle_keypress(int keysym, t_img *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx_connect, data->mlx_window);
        data->mlx_window = NULL;
    }
    return (0);
}
int rect(t_img *img)
{
	if (img->mlx_window ==  NULL)
		return (1);
	img->ypos = img->height * 0.1;
	img->xpos = img->width * 0.1;
	printf("height=%d\n",img->height);	
	while (++img->xpos < img->width * 0.9) // boucle pour creer la ligne/diagonale
	{
		while (++img->ypos < img->height * 0.9)
		{
			mlx_pixel_put(img->mlx_connect, img->mlx_window, img->xpos, img->ypos, rand() % 0x10000000);
		}
		img->ypos = img->height * 0.1;		
	}
	mlx_string_put(img->mlx_connect, img->mlx_window, img->width * 0.8, img->height * 0.95, 0xFF0000, "first test");
	return (0);
}
int main()
{
	t_img img;
	img.mlx_connect = mlx_init(); // etabli la connection avec le server graphique
	if (!img.mlx_connect)
		return (1);
	img.height = 400;
	img.width = 600;
	
	img.mlx_window = mlx_new_window(img.mlx_connect, img.width, img.height, "first window"); // cree une fenetre
	if (!img.mlx_window)
	{
		free(img.mlx_window);
		return (1);
	}	
	mlx_loop_hook(img.mlx_window, &rect, &img);
	mlx_hook(img.mlx_window, KeyPress, KeyPressMask, &handle_keypress, &img);
	mlx_loop(img.mlx_connect);
	mlx_destroy_window(img.mlx_connect, img.mlx_window);
	mlx_destroy_display(img.mlx_connect);
	free(img.mlx_connect);
	return (0);
}