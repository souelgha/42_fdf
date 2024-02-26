/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:37:11 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/26 17:21:32 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
# define FDF_H

#include "../minilibx-linux/mlx.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../libft/includes/ft_printf.h"
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <X11/keysym.h>
#include <X11/Xlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_img
{
	void	*img_ptr; //ptr sur l image
	char	*addr_pix; //adress du 1er pixel
	int		bpp; //bit/pixel 
	int		line_len; //longueur de l image
	int		endian; // type d endian
}	t_img;

typedef struct	s_data
{
	void	*mlx_connect;
	void	*mlx_window;
	t_img	img;
}	t_data;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

/*** structure du pixel, x, y, z, color ***/
typedef struct s_pix
{
	int				x_map;
	int				y_map;
	int				height;
	char			*color;
	int				x_pix;
	int				y_pix;
	struct s_pix	*next;

}	t_pix;

/****structure du fichier *****/
typedef struct s_file
{
	int	x;  //x
	int	y;
	int	pix;

}	t_file;

int		close_win(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int 	code_trgb(int t, int red, int green, int blue);
void	color_rect(t_data *data, int color);
void	my_pixel_put(t_img *img,int x, int y, int color);
int 	render_rect(t_img *img, t_rect rect);
int		render(t_data *data);
int		keyfunc(int keysym);

int 	check_arg(int argc, char **argv);
int		pars_file(char *file, t_pix **pix);
t_pix	*newpix(int	i, int j, char *pixel);
void	initmap(t_pix **map, int i, int j, char *pix);
void	ft_lstclear_s(t_pix **lst);
void	ft_lstadd_back_s(t_pix **lst, t_pix *new_node);
void	affiche_list(t_pix *map);

# endif