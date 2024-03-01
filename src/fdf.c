/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:33 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/01 17:33:22 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_data	data; 	//connect & window

	data.node = NULL;
	if(!check_arg(argc, argv))
		return(1);
	pars_file(argv[1], &data.node);
	connect_right(data.node);
	connect_down(data.node);
	printf("\n");	
	//affiche_list(data.node);
	file_colums_rows(&data);
	config_win_img(&data);
	mlx_loop_hook(data.mlx_connect, render, &data);	
	//printf("line_len=%d\nbpp=%d\nendian=%d\n", data.img.line_len, data.img.bpp, data.img.endian);
	mlx_hook(data.mlx_window, 17, 1L<<5, close_win, &data);
	mlx_hook(data.mlx_window, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_key_hook(data.mlx_window, keyfunc, 0);
	mlx_string_put(data.mlx_connect, data.mlx_window, 1800 * 0.8, 1000 * 0.95, 0xFF0000, "first test");
	mlx_loop(data.mlx_connect);
	destroy_fct(&data);
	return (0);
}