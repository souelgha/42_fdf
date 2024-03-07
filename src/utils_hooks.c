/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:09 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/07 15:17:38 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int	keyfunc(int keysym)
{
    printf("key event %d\n", keysym);
    return (0);
}

int	close_win(t_data *data)
{

    mlx_destroy_window(data->mlx_connect, data->mlx_window);
	data->mlx_window = NULL;
    return (0);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if ( x < 0 || x >= IMGX || y < 0 || y >= IMGY)
		return;
	pixel = img->addr_pix + (img->line_len * y) + ( x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}


 int code_rgb(int red, int green, int blue)
{
 	return (red << 16 | green << 8 | blue);
}

/*int putline(t_data *data, t_pix *point)
{
    int	i;
    int j;
//	t_pix *ptr;

//	ptr = *point;
	if (data->mlx_window == NULL)
        return (1);
    i = point->x_map;
	point->x_pix = 50; //offset de 50 pixels

	point->color = 0xFFFF00;	
    while (i < rect.height)
    {
        j = point->color;
        while (j < (WINX / 2))
            my_pixel_put(&data->img, j++, i, point->color);
        ++i;
    }
	mlx_put_image_to_window(data->mlx_connect, data->mlx_window, 
							data->img.img_ptr, WINX / 4, WINY / 4);//centre l'image
    return (0);
}*/
