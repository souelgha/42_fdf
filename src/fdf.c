/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:42:33 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/22 17:23:55 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_data data;
	if(!check_arg(argc, argv))
		return(1);
	data.mlx_connect = mlx_init(); 
	if (!data.mlx_connect)
	{
		free(data.mlx_connect);
		return (1);
	}		

	data.mlx_window = mlx_new_window(data.mlx_connect, 600, 400, "first window"); 
	if (!data.mlx_window)
	{
		mlx_destroy_display(data.mlx_connect);
		free(data.mlx_window);
		return (1);
	}
	data.img.img_ptr =  mlx_new_image(data.mlx_connect, 400, 300);
	data.img.addr_pix = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_connect, render, &data);
	printf("line_len=%d\nbpp=%d\nendian=%d\n", data.img.line_len, data.img.bpp, data.img.endian);
	mlx_hook(data.mlx_window, 17, 1L<<5, close_win, &data);
	mlx_hook(data.mlx_window, KeyPress, KeyPressMask, handle_keypress, &data);
	mlx_key_hook(data.mlx_window, keyfunc, 0);
	mlx_string_put(data.mlx_connect, data.mlx_window, 600 * 0.8, 400 * 0.95, 0xFF0000, "first test");
	mlx_loop(data.mlx_connect);
	mlx_destroy_image(data.mlx_connect, data.img.img_ptr);
	mlx_destroy_display(data.mlx_connect);
	free(data.mlx_connect);
	return (0);
}