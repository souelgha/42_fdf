/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_angles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:54:29 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/15 15:21:16 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	img_centering(t_data *data)
{
	int	dx;
	int	dy;
	t_pix	*current;

	current = data->node;
	dx = (IMGX * 0.9) / (data->x_colunms * 2 );
	dy = (IMGY * 0.9) / (data->y_row * 2); 
	if (data->x_colunms >= 200 && data->y_row >= 200)
		data->shift = 2;
	else if ((data->x_colunms >= 100 && data->x_colunms <= 200) || (data->y_row >= 100 && data->y_row <= 200))
		data->shift = 6;
	else if ((data->x_colunms >= 50 && data->x_colunms < 100) || (data->y_row >= 50 && data->y_row < 100))
		data->shift = 10;
	else if (dx > 40 && dy > 40 && (data->x_colunms > 20 || data->y_row > 20))
		data->shift = 40;
	else if (dx <= dy)
		data->shift = dx;
	else
		data->shift = dy;
	ft_printf("dx=%d\tdy=%d\tshift= %d\n", dx, dy, data->shift);
	while (current)
	{
		current->x_pix = current->x_map * (data->shift);
		current->y_pix = current->y_map * (data->shift);
		current = current->next;
	}
}

/** calcul de la longueur tt en x pour avoir tous les pixels en x dans le fentre ****/
/***ces longueurs doivent etre < taille de l image ****/
void	perimetre_total(t_data *data)
{
	t_pix	*current;

	current = data->node;
	while (current->next != NULL)
		current = current->next;
	data->xtot_hypo = data->shift * (data->x_colunms * 2);
	data->ytot_hypo = data->shift * (data->y_row  * 2);
	ft_printf("hx=%d\t", data->xtot_hypo);
	ft_printf("hy=%d\n", data->ytot_hypo);
}
/**ajustement de la position du pixel avec teta *****/

void	adj_coord(t_data *data, t_pix **head)
{
	t_pix	*current;
	int		x_orig;
	int		y_orig;

	current = *head;
	if (data->xtot_hypo < WINX && data->ytot_hypo < WINY)
	{
		x_orig = WINX/3;
	 	y_orig = WINY/3;
	}
	else if (data->shift == 2 || data->shift == 6)
	{
		x_orig = WINX/3;
		y_orig = WINY/4;
	}
	else 
	{
		x_orig = WINX/2 - data->shift * data->x_colunms;
		y_orig = WINY/2 - data->shift * data->y_row;
	}
	ft_printf("WINX/2=%d\tWINX/3=%d\tx_orig=%d\tWINY/2=%d\tWINY/3=%d\ty_orig=%d\n", WINX/2, WINX/3, x_orig, WINY/2, WINY/3, y_orig);
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
	printf("ratio_z=%d\n", data->ratio_z);
	while (current)
	{
		current->x_adjust = x_orig + (current->x_pix * cos(TETA) - current->y_pix * sin(TETA))  ;
		current->y_adjust = y_orig + ((current->y_pix * cos(TETA) + current->x_pix * sin(TETA))) / 2 - (current->z_map  * data->ratio_z);
		current = current->next;
	}
}
