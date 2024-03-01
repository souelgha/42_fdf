/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:56:30 by sonia             #+#    #+#             */
/*   Updated: 2024/03/01 18:10:44 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	bres_y(t_data *data, t_pix *start, t_pix *end)
{
	int x;
	int	y;
	int p;
	int dy;
	int dx;

	x = start->x_pix;
	y = start->y_pix;
	dx =  end->x_pix - start->x_pix;
	dy =  end->y_pix - start->y_pix;
	p = 2 * dx - dy;
	while (y != end->y_pix)
	{
		my_pixel_put(&data->img, x, y, 0xFFFFFF);
		y++;
		if (p < 0)
		 	p = p + 2 * dx;
		else 
		{
			p = p + 2*dx - 2*dy;
			x++;
		}
	}
}
static void	bres_x(t_data *data, t_pix *start, t_pix *end)
{
	int x;
	int	y;
	int p;
	int dy;
	int dx;

	x = start->x_pix;
	y = start->y_pix;
	dx =  end->x_pix - start->x_pix;
	dy =  end->y_pix - start->y_pix;
	p = 2 * dy - dx;
	while (x != end->x_pix)
	{
		my_pixel_put(&data->img, x, y, 0xFFFFFF);
		x++;
		if (p < 0)
		 	p = p + 2 * dy;
		else 
		{
			p = p + 2*dy - 2*dx;
			y++;
		}
	}
}
void	bresenham(t_data *data, t_pix *start, t_pix *end)
{
	int	delta_x;
	int	delta_y;

	delta_x = abs(end->x_pix - start->x_pix);
	delta_y = abs(end->y_pix - start->y_pix);
	if (delta_x >= delta_y)
		bres_x(data, start, end);
	else
		bres_y(data, start, end);
	my_pixel_put(&data->img, end->x_pix, end->y_pix, 0xFF0000);
}
void	draw_lines(t_data *data, t_pix **head)
{
	t_pix	*current;

	current = *head;
	while (current != NULL)
	{
		if (current->line_right != NULL)
			bresenham(data, current, current->line_right);
		if (current->line_down != NULL)
			bresenham(data, current, current->line_down);
		current = current->next;
	}
}

int render(t_data *data)
{
	if (data->mlx_window == NULL)
		return (1);
	draw_lines(data, &data->node);
	mlx_put_image_to_window(data->mlx_connect, data->mlx_window, data->img.img_ptr, WINX / 4, WINY / 4);
	return (0);
}
