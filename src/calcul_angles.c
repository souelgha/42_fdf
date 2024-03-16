/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_angles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:54:29 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/16 15:13:52 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	shifting_def(t_data *data, int dx, int dy)
{
	if (data->x_colunms >= 200 && data->y_row >= 200)
		data->shift = 2;
	else if ((data->x_colunms >= 100 && data->x_colunms <= 200)
		|| (data->y_row >= 100 && data->y_row <= 200))
		data->shift = 6;
	else if ((data->x_colunms >= 50 && data->x_colunms < 100)
		|| (data->y_row >= 50 && data->y_row < 100))
		data->shift = 10;
	else if (dx > 40 && dy > 40 && (data->x_colunms > 20 || data->y_row > 20))
		data->shift = 40;
	else if (dx <= dy)
		data->shift = dx;
	else
		data->shift = dy;
}

/**********definition des offsets*************/
void	img_settings(t_data *data)
{
	int		dx;
	int		dy;
	t_pix	*current;

	current = data->node;
	dx = (WINX * 0.9) / (data->x_colunms * 2);
	dy = (WINY * 0.9) / (data->y_row * 2);
	shifting_def(data, dx, dy);
	ft_printf("dx=%d\tdy=%d\tshift= %d\n", dx, dy, data->shift);
	while (current)
	{
		current->x_pix = current->x_map * (data->shift);
		current->y_pix = current->y_map * (data->shift);
		current = current->next;
	}
}

/**ajustement de la position du pixel avec teta *****/
static void	scale_z(t_data *data)
{
	if (data->shift >= 40)
		data->ratio_z = data->shift * 0.08;
	else if (data->shift >= 20 && data->shift < 40)
		data->ratio_z = data->shift * 0.2;
	else if (data->shift >= 10 && data->shift < 20)
		data->ratio_z = data->shift * 0.5;
	else if (data->shift < 10 && data->shift > 2)
		data->ratio_z = data->shift * 0.6;
	else if (data->shift == 2)
		data->ratio_z = data->shift ;
}

void	adj_coord(t_data *data, t_pix **head)
{
	t_pix	*current;
	int		x_orig;
	int		y_orig;

	current = *head;
	x_orig = WINX / 3;
	if (data->shift == 2 || data->shift == 6)
		y_orig = WINY / 4;
	else
		y_orig = WINY / 3;
	ft_printf("WINX/2=%d\tWINX/3=%d\tx_orig=%d\nWINY/2=%d\tWINY/3=%d\ty_orig=%d\n",
		WINX / 2, WINX / 3, x_orig, WINY / 2, WINY / 3, y_orig);
	scale_z(data);
	ft_printf("ratio_z=%d\n", data->ratio_z);
	while (current)
	{
		current->x_adjust = x_orig + (current->x_pix * cos(TETA)
				- current->y_pix * sin(TETA));
		current->y_adjust = y_orig + ((current->y_pix * cos(TETA)
					+ current->x_pix * sin(TETA))) / 2
			- (current->z_map * data->ratio_z);
		current = current->next;
	}
}
