/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:37:11 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/21 19:19:14 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <stdio.h>

typedef struct s_img
{
	void	*img_ptr; //ptr sur l image
	char	*addr_pixel; //adress du 1er pixel
	int		bits_per_pixel; //bit/pixel 
	int		line_len; //longueur de l image
	int		endian; // type d endian
}	t_img;

typedef struct	s_data
{
	void	*mlx_connect;
	void	*mlx_window;
	t_img	img;
}	t_data;


int	close_win(t_data *data);
int	handle_keypress(int keysym, t_data *data);
int code_trgb(int t, int red, int green, int blue);
void color_rect(t_data *data, int color);
int f(int keysym, t_data *data);
void	my_pixel_put(t_img *img,int x, int y, int color);


# endif