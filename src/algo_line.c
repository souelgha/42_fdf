/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:56:30 by sonia             #+#    #+#             */
/*   Updated: 2024/03/15 14:41:37 by sonouelg         ###   ########.fr       */
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
static void	bres_ypos(t_data *data, t_pix *start, t_pix *end)
{
	int x;
	int	y;
	int p;
	int signx;
	int signy;

	x = start->x_adjust;
	y = start->y_adjust;
	p = 2 * data->dx - data->dy;
	signx = signstep(start->x_adjust, end->x_adjust);
	signy = signstep(start->y_adjust, end->y_adjust);
	while (y < end->y_adjust)
	{
		my_pixel_put(&data->img, x, y, start->color);
		y+=signy;
		if (p < 0)
		 	p = p + (2 * data->dx);
		else 
		{
			x += signx;
			p = p + (2 * data->dx) - (2 * data->dy);
		}
	}
}
static void	bres_yneg(t_data *data, t_pix *start, t_pix *end)
{
	int x;
	int	y;
	int p;
	int signx;
	int signy;

	x = start->x_adjust;
	y = start->y_adjust;
	p = 2 * data->dx - data->dy;
	signx = signstep(start->x_adjust, end->x_adjust);
	signy = signstep(start->y_adjust, end->y_adjust);
	while (y > end->y_adjust)
	{
		my_pixel_put(&data->img, x, y, start->color);
		y+=signy;
		if (p < 0)
		 	p = p + (2 * data->dx);
		else 
		{
			x += signx;
			p = p + (2 * data->dx) - (2 * data->dy);
		}
	}
}
static void	bres_xneg(t_data *data, t_pix *start, t_pix *end)
{
	int x;
	int	y;
	int p;
	int signy;

	x = start->x_adjust;
	y = start->y_adjust;
	p = 2 * data->dy - data->dx;
	signy = signstep(start->y_adjust, end->y_adjust);
	while (x > end->x_adjust)
	{
		my_pixel_put(&data->img, x, y, start->color);
		x--;
		if (p < 0)
			p = p + (2 * data->dy);
		else 
		{
			p = p + (2 * data->dy) - (2 * data->dx);
			y+=signy;
		}
	}
}

static void	bres_xpos(t_data *data, t_pix *start, t_pix *end)
{
	int x;
	int	y;
	int p;
	int signy;

	x = start->x_adjust;
	y = start->y_adjust;
	p = 2 * data->dy - data->dx;
	signy = signstep(start->y_adjust, end->y_adjust);
	while (x < end->x_adjust)
	{
		my_pixel_put(&data->img, x, y, start->color);
		x++;
		if (p < 0)
			p = p + (2 * data->dy);
		else 
		{
			p = p + (2 * data->dy) - (2 * data->dx);
			y+=signy;
		}
	}
}
static void	bres_y(t_data *data, t_pix *start, t_pix *end)
{

	int signy;

	signy = signstep(start->y_adjust, end->y_adjust);
	if (signy == 1)
		bres_ypos(data, start, end);
	else
		bres_yneg(data, start, end);
}

static void	bres_x(t_data *data, t_pix *start, t_pix *end)
{

	int signx;

	signx = signstep(start->x_adjust, end->x_adjust);
	if (signx == 1)
		bres_xpos(data, start, end);
	else
		bres_xneg(data, start, end);
}

void	bresenham(t_data *data, t_pix *start, t_pix *end)
{
	int	delta_x;
	int	delta_y;

	delta_x = abs(end->x_adjust - start->x_adjust);
	delta_y = abs(end->y_adjust - start->y_adjust);
	data->dx = delta_x;
	data->dy = delta_y;
	if (delta_x >= delta_y)
		bres_x(data, start, end);
	else
		bres_y(data, start, end);
	my_pixel_put(&data->img, end->x_adjust, end->y_adjust, end->color);
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
void	points(t_data *data)
{
	t_pix *current;

	current = data->node;
	while (current)
	{
		my_pixel_put(&data->img, current->x_adjust, current->y_adjust, 0xFFFF00);
		current = current->next;
	}
}

int render(t_data *data)
{
	if (data->mlx_window == NULL)
		return (1);
//	points(data);
	draw_lines(data, &data->node);
	mlx_put_image_to_window(data->mlx_connect, data->mlx_window, data->img.img_ptr, 0, 0);
	return (0);
}

/*static void	bres_x(t_data *data, t_pix *start, t_pix *end)
{
	int x;
	int	y;
	int p;
	int signy;
	int signx;

	x = start->x_adjust;
	y = start->y_adjust;
	p = 2 * data->dy - data->dx;
	signy = signstep(start->y_adjust, end->y_adjust);
	signx = signstep(start->x_adjust, end->x_adjust);
	while (x < end->x_adjust)
	{
		my_pixel_put(&data->img, x, y, start->color);
		x+=signx;
		if (p < 0)
			p = p + (2 * data->dy);
		else 
		{
			p = p + (2 * data->dy) - (2 * data->dx);
			y+=signy;
		}
	}
}*/
