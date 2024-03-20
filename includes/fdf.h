/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:37:11 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/18 12:10:13 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include <stdlib.h>
# include <stdint.h>
# include <math.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <fcntl.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*addr_pix;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

/*** structure du point dans la map ***/
typedef struct s_pix
{
	int				x_map;
	int				y_map;
	int				z_map;
	unsigned long	color;
	int				x_pix;
	int				y_pix;
	int				x_adjust;
	int				y_adjust;
	struct s_pix	*next;
	struct s_pix	*line_down;	
	struct s_pix	*line_right;
}	t_pix;

typedef struct s_data
{
	void	*mlx_connect;
	void	*mlx_window;
	int		winx;
	int		winy;
	int		x_colunms;
	int		y_row;
	int		xtot_hypo;
	int		ytot_hypo;
	int		dx;
	int		dy;
	int		shift;
	int		ratio_z;
	t_img	img;
	t_pix	*node;
}	t_data;

int				close_win(t_data *data);
void			global_set(t_data *data);
int				config_win_img(t_data *data);
int				check_arg(int argc, char **argv);
int				pars_file(char *file, t_pix **pix);
unsigned long	ft_atoi_hexa(const char *str);
void			my_pixel_put(t_img *img, int x, int y, int color);
int				render(t_data *data);
int				handle_keypress(int keysym, t_data *data);
int				keyfunc(int keysym);
void			initmap(t_pix **map, int i, int j, char *pix);
t_pix			*newpix(int i, int j, char *pixel);
void			ft_lstadd_back_s(t_pix **lst, t_pix *new_node);
void			affiche_list(t_pix *map);
void			ft_lstclear_s(t_pix **lst);
void			destroy_fct(t_data *data);
void			get_free(char **tab);
void			connect_right(t_pix *head);
void			connect_down(t_pix *head);
void			file_colums_rows(t_data *data, t_pix *pix);
void			img_settings(t_data *data);
void			adj_coord(t_data *data, t_pix **head);
void			points(t_data *data);
void			draw_lines(t_data *data, t_pix **head);
int				signstep(int start, int end);
void			bres_x(t_data *data, t_pix *start, t_pix *end);
void			bres_y(t_data *data, t_pix *start, t_pix *end);

#endif