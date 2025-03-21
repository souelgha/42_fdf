/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:14:32 by sonia             #+#    #+#             */
/*   Updated: 2024/03/18 11:53:23 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	config_win_img(t_data *data)
{
	data->mlx_connect = mlx_init();
	if (!data->mlx_connect)
	{
		free(data->mlx_connect);
		return (1);
	}
	data->mlx_window = mlx_new_window(data->mlx_connect,
			data->winx, data->winy, "fdf_Graphic");
	if (!data->mlx_window)
	{
		mlx_destroy_display(data->mlx_connect);
		free(data->mlx_window);
		return (1);
	}
	data->img.img_ptr = mlx_new_image(data->mlx_connect,
			data->winx, data->winy);
	data->img.addr_pix = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp, &data->img.line_len, &data->img.endian);
	return (0);
}

void	destroy_fct(t_data *data)
{
	mlx_destroy_image(data->mlx_connect, data->img.img_ptr);
	mlx_destroy_display(data->mlx_connect);
	free(data->mlx_connect);
	ft_lstclear_s(&data->node);
}
