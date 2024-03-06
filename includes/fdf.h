/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:37:11 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/06 18:29:36 by sonouelg         ###   ########.fr       */
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

# define WINX 1920	
# define WINY 1080
# define IMGX 1000	
# define IMGY 800
# define TETA 0.636 //30degres


typedef struct s_img
{
	void	*img_ptr; //ptr sur l image
	char	*addr_pix; //adress du 1er pixel
	int		bpp; //bit/pixel 
	int		line_len; //longueur de l image
	int		endian; // type d endian
}	t_img;


/*** structure du point dans la map ***/
typedef struct s_pix
{
	int				x_map;
	int				y_map;
	int				height;
	unsigned long	color;
	int				x_pix;
	int				y_pix;
	int				x_adjust;
	int				y_adjust;
	struct s_pix	*next;
	struct s_pix	*line_down;	// lien vers le bas
	struct s_pix	*line_right; // lien vers la droite 

}	t_pix;

typedef struct	s_data
{
	void	*mlx_connect;
	void	*mlx_window;
	int		x_colunms;
	int		y_row;
	int		xtot_hypo;
	int		ytot_hypo;
//	int		dx;
//	int		dy;
	int		shift;
	t_img	img;
	t_pix	*node;
}	t_data;

/****structure du fichier *****/
typedef struct s_file
{
	int	x;  
	int	y;
	int	pix;

}	t_file;

int		close_win(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int 	code_trgb(int t, int red, int green, int blue);
void	color_rect(t_data *data, int color);
unsigned long	ft_atoi_hexa(const char *str);
void	my_pixel_put(t_img *img,int x, int y, int color);
int		render(t_data *data);
int		keyfunc(int keysym);
int		config_win_img(t_data *data);
int 	check_arg(int argc, char **argv);
int		pars_file(char *file, t_pix **pix);
t_pix	*newpix(int	i, int j, char *pixel);
void	initmap(t_pix **map, int i, int j, char *pix);
void	ft_lstclear_s(t_pix **lst);
void	ft_lstadd_back_s(t_pix **lst, t_pix *new_node);
void	affiche_list(t_pix *map);
void 	connect_right(t_pix *head);
void 	connect_down(t_pix *head);
//void 	file_colums_rows(t_data *data);
void 	file_colums_rows(t_data *data, t_pix *pix);
void	img_centering(t_data *data);
void	hypo_total(t_data *data);
void	adj_coord(t_data *data, t_pix **head);

void	destroy_fct(t_data *data);


# endif