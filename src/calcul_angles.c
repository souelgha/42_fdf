/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_angles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:54:29 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/11 15:57:12 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	img_centering(t_data *data)
{
	int	dx;
	int	dy;
	t_pix	*current;

	current = data->node;
	dx = (IMGX * 0.8) / (data->x_colunms * 2 );
	dy = (IMGY * 0.8) / (data->y_row * 2); 
	if (data->x_colunms > 200 || data->y_row > 200)
		data->shift = 1;
	else if (dx <= dy && data->x_colunms < 200 )
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

	current = *head;
	if (data->shift == 2)
		x_orig = WINX/2;
	else 
		x_orig = data->y_row / tan(TETA) * data->shift + 50;
	ft_printf("x_orig=%d\n", x_orig);
	while (current)
	{
		while (current->line_right)
		{
			current->x_adjust = current->x_pix + x_orig;
			current->y_adjust = current->y_pix + current->x_pix * tan(TETA);
			current = current->next;
		}
		if (current)
		{
			current->x_adjust = current->x_pix + x_orig;
			current->y_adjust = current->y_pix + current->x_pix * tan(TETA);		
			current = current->next;			
		}
		x_orig = x_orig - data->shift;
		if (current)
		{
			current->x_adjust = x_orig;
			current->y_adjust = current->y_pix;
			current = current->next;
		}
	}
}