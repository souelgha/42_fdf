/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:37:11 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/20 16:22:03 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

#include "../../minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdint.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <stdio.h>

typedef struct	s_data
{
	void	*mlx_connect;
	void	*mlx_window;
	int		winheight;
	int 	winwidth;
}	t_data;

typedef struct s_img
{
	int		height;
	int 	width;
	int 	xpos;
	int		ypos;
	int		color;
}	t_img;

# endif