#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdint.h>

// int code_rgb(unit8_t red, unit8_t green, unit8_t blue)
// {
// 	return (red << 16 | green << 8 | blue);
// }

int main()
{
	void *mlx_connection;
	void	*mlx_window;
	int	height;
	int width;
	int x, y;

	mlx_connection = mlx_init(); // etabli la connection avec le server graphique
	if (!mlx_connection)
		return (1);
	height = 400;
	width = 600;
	y = height * 0.1;
	x = width * 0.1;
	mlx_window = mlx_new_window(mlx_connection, width, height, "first window"); // cree une fenetre
	if (!mlx_window)
	{
		free(mlx_window);
		return (1);
	}		
	while (++x < width * 0.9) // boucle pour creer la ligne/diagonle
	{
		while (++y < height * 0.9)
		{
			mlx_pixel_put(mlx_connection, mlx_window, x, y, rand() % 0x10000000);
		}
		y = height * 0.1;
		//ouvrir la connection , ouvrir la fenetre , donner les coordonnees du pixel 
		// et sa couleur en hexa (0x). faire un rectangle dynamique
	}
	mlx_string_put(mlx_connection, mlx_window, width * 0.8, height * 0.95, 0xFF0000, "first test");
	mlx_loop(mlx_connection);
	mlx_destroy_window(mlx_connection, mlx_window);
	mlx_destroy_display(mlx_connection);
	free(mlx_connection);
	return (0);
}