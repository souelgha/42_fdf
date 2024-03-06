/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_angles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:54:29 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/06 11:36:48 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

/** calcul de longueur hypo en x & y avec teta =  30degres*/
/***ces longueurs doivent etre < taille de l image ****/
void hypo_total(t_data *data)
{
	t_pix *current;

	current = data->node;
	while (current->next != NULL)
		current = current->next;
	data->xtot_hypo = current->x_pix / cos(TETA);
	data->ytot_hypo = current->y_pix / cos(TETA);
	printf("hx=%d\t", data->xtot_hypo);
	printf("hy=%d\n", data->ytot_hypo);
}
/**ajustement de la position du pixel avec teta *****/

void	adj_coord(t_data *data, t_pix **head)
{
	t_pix *current;
	int		x_orig;

	current = *head;
	x_orig = data->ytot_hypo + 10;
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
		x_orig = x_orig - data->shift * tan(TETA);
		if (current) // 2e line
		{
			current->x_adjust = x_orig;
			current->y_adjust = current->y_pix;
			current = current->next;
		}		
	}

}