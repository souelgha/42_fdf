/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_angles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:54:29 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/07 18:11:10 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	img_centering(t_data *data)
{
	int	delta;  //ecart entre 2 points en pixels.
	int	dx;
	int	dy;
	t_pix	*current;

	current = data->node;
	// dx = (IMGX*0.8) / (data->x_colunms);
	// dy = (IMGY*0.8) / (data-> y_row); 
	dx = (IMGX*0.8) / (data->x_colunms + data->y_row * tan(ALPHA));
	dy = (IMGY*0.8) / (data->y_row + data->x_colunms * tan(TETA)); 
	if (dx <= dy)
		delta = dx;
	else
		delta = dy;
	data->shift = delta;
	ft_printf("dx=%d\tdy=%d\tshift= %d\n", dx, dy, data->shift);
	while (current)
	{
		current->x_pix = current->x_map * (delta);
		current->y_pix = current->y_map * (delta);
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
	data->xtot_hypo = data->shift * (data->x_colunms + data->y_row * tan(ALPHA));
	data->ytot_hypo = data->shift * (data->y_row + data->x_colunms * tan(TETA));
	ft_printf("hx=%d\t", data->xtot_hypo);
	ft_printf("hy=%d\n", data->ytot_hypo);
}
/**ajustement de la position du pixel avec teta *****/

void	adj_coord(t_data *data, t_pix **head)
{
	t_pix	*current;
	int		x_orig;

	current = *head;
	//x_orig = data->ytot_hypo + 5;
	//x_orig = WINX/4;
	x_orig = data->y_row * tan(ALPHA) * data->shift + 200;
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
		x_orig = x_orig - data->shift * tan(ALPHA);
		if (current) // 2e line
		{
			current->x_adjust = x_orig;
			current->y_adjust = current->y_pix;
			current = current->next;
		}
	}
}