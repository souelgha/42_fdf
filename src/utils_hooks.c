/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:09 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/28 16:55:57 by sonia            ###   ########.fr       */
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

	pixel = img->addr_pix + (img->line_len * y) + ( x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

/*int render(t_data *data, t_rect rect)
{
    int	i;
    int j;
	if (data->mlx_window == NULL)
        return (1);
    i = rect.y;
	rect.height = WINY * 0.5;
	rect.width = WINX * 0.5;
	rect.color = 0xFFFF00;
	rect.x = 0;
	rect.y = 0;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            my_pixel_put(&data->img, j++, i, rect.color);
        ++i;
    }
	mlx_put_image_to_window(data->mlx_connect, data->mlx_window, 
							data->img.img_ptr, WINX / 4, WINY / 4);//centre l'image
    return (0);
}*/

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
