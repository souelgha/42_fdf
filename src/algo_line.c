/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:56:30 by sonia             #+#    #+#             */
/*   Updated: 2024/03/06 18:29:12 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int signstep(int start, int end)
{
	if(start < end)
		return (1);
	else 
		return (-1);
}
static void	bres_y(t_data *data, t_pix *start, t_pix *end)
{
	int x;
	int	y;
	int p;
	int dy;
	int dx;
	int signx;
	int signy;

	x = start->x_adjust;
	y = start->y_adjust;
	dx = abs(end->x_adjust - start->x_adjust);
	dy = abs(end->y_adjust - start->y_adjust);
	p = 2 * dx - dy;
	signx = signstep(start->x_adjust, end->x_adjust);
	signy = signstep(start->y_adjust, end->y_adjust);
	while (y <= end->y_adjust)
	{
		my_pixel_put(&data->img, x, y, 0xFFFFFF);
		y+=signy;
		if (p < 0)
		 	p = p + 2 * dx;
		else 
		{
			x += signx;
			p = p + 2*dx - 2*dy;
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
	int signx;
	int signy;

	x = start->x_adjust;
	y = start->y_adjust;
	dx = abs(end->x_adjust - start->x_adjust);
	dy = abs(end->y_adjust - start->y_adjust);
	p = 2 * dy - dx;
	//p = 2 * data->dy - data->dx;
	signx = signstep(start->x_adjust, end->x_adjust);
	signy = signstep(start->y_adjust, end->y_adjust);
	while (x <= end->x_adjust)
	{
		my_pixel_put(&data->img, x, y, 0xFFFFFF);
		x += signx;
		if (p < 0)
		{
		 	p = p + 2 * dy;
			//p = p + 2 * data->dy;
		}
		else 
		{
			p = p + 2*dy - 2*dx;
			//p = p + 2 * data->dy - 2 * data->dx;
			y+=signy;
		}
	}
}

void	bresenham(t_data *data, t_pix *start, t_pix *end)
{
	int	delta_x;
	int	delta_y;

	delta_x = abs(end->x_adjust - start->x_adjust);
	delta_y = abs(end->y_adjust - start->y_adjust);
	//data->dx = delta_x;
	//data->dy = delta_y;
	if (delta_x >= delta_y)
		bres_x(data, start, end);
	else
		bres_y(data, start, end);
	//my_pixel_put(&data->img, end->x_adjust, end->y_adjust, 0xFF0000);
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
	mlx_put_image_to_window(data->mlx_connect, data->mlx_window, data->img.img_ptr, 50, 50);
	return (0);
}
// void	bresenham(t_data *data, t_pix *start, t_pix *end)
// {
// 	int	delta_x;
// 	int	delta_y;

// 	delta_x = abs(end->x_pix - start->x_pix);
// 	delta_y = abs(end->y_pix - start->y_pix);
// 	if (delta_x >= delta_y)
// 		bres_x(data, start, end);
// 	else
// 		bres_y(data, start, end);
// 	my_pixel_put(&data->img, end->x_pix, end->y_pix, 0xFF0000);
// }

// static void	bres_y(t_data *data, t_pix *start, t_pix *end)
// {
// 	int x;
// 	int	y;
// 	int p;
// 	int dy;
// 	int dx;

// 	x = start->x_adjust;
// 	y = start->y_adjust;
// 	dx =  end->x_adjust - start->x_adjust;
// 	dy =  end->y_adjust - start->y_adjust;
// 	p = 2 * dx - dy;
// 	while (y != end->y_adjust)
// 	{
// 		my_pixel_put(&data->img, x, y, 0xFFFFFF);
// 		y++;
// 		if (p < 0)
// 		 	p = p + 2 * dx;
// 		else 
// 		{
// 			p = p + 2*dx - 2*dy;
// 			x++;
// 		}
// 	//	printf("bres_y => x=%d\ty=%d\n", x, y);
// 	}
// }