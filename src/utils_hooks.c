/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:09 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/22 16:43:19 by sonouelg         ###   ########.fr       */
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

int render_rect(t_img *img, t_rect rect)
{
    int	i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            my_pixel_put(img, j++, i, rect.color);
        ++i;
    }
    return (0);
}

int	render(t_data *data)
{
    if (data->mlx_window == NULL)
        return (1);
    render_rect(&data->img, (t_rect){0, 0, 100, 100, 0xFF0000});
    mlx_put_image_to_window(data->mlx_connect, data->mlx_window, data->img.img_ptr, 0, 0);
	return (0);
}

 int code_trgb(int t, int red, int green, int blue)
{
 	return (t << 24 | red << 16 | green << 8 | blue);
}
