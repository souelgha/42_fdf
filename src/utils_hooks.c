/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:09 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/19 11:31:04 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_connect, data->mlx_window);
		destroy_fct(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx_connect, data->mlx_window);
	destroy_fct(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= 1920 || y < 0 || y >= 1080)
		return ;
	pixel = img->addr_pix + (img->line_len * y) + (x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
