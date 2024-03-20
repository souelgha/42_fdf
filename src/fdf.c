/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:33 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/19 11:28:10 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	global_set(t_data *data)
{
	connect_right(data->node);
	connect_down(data->node);
	file_colums_rows(data, data->node);
	img_settings(data);
	adj_coord(data, &data->node);
}

int	render(t_data *data)
{
	if (data->mlx_window == NULL)
		return (1);
	draw_lines(data, &data->node);
	mlx_put_image_to_window(data->mlx_connect,
		data->mlx_window, data->img.img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.node = NULL;
	if (!check_arg(argc, argv))
		return (1);
	pars_file(argv[1], &data.node);
	global_set(&data);
	config_win_img(&data);
	mlx_loop_hook(data.mlx_connect, render, &data);
	ft_printf("line_len=%d\nbpp=%d\nendian=%d\n",
		data.img.line_len, data.img.bpp, data.img.endian);
	mlx_hook(data.mlx_window, 17, 1L << 5, close_win, &data);
	mlx_hook(data.mlx_window, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_loop(data.mlx_connect);
	return (0);
}
