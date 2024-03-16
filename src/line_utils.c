/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:19:24 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/16 12:30:59 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	connect_right(t_pix *head)
{
	t_pix	*ptr;

	ptr = head;
	while (ptr->next != NULL)
	{
		if (ptr->next->y_map == ptr->y_map)
			ptr->line_right = ptr->next;
		ptr = ptr->next;
	}
}

void	connect_down(t_pix *head)
{
	t_pix	*ptr;
	t_pix	*current;

	current = head;
	ptr = head;
	while (ptr->line_right)
		ptr = ptr->next;
	ptr = ptr->next;
	while (ptr)
	{
		if (ptr->x_map == current->x_map)
			current->line_down = ptr;
		current = current->next;
		ptr = ptr->next;
	}
}

void	points(t_data *data)
{
	t_pix	*current;

	current = data->node;
	while (current)
	{
		my_pixel_put(&data->img, current->x_adjust,
			current->y_adjust, 0xFFFF00);
		current = current->next;
	}
}

/** nombre le lignes et colonnes dans le fichier ***/
void	file_colums_rows(t_data *data, t_pix *lst)
{
	t_pix	*ptr;
	int		i;
	int		j;

	ptr = lst;
	i = 0;
	j = 0;
	while (ptr->line_right != NULL)
	{
		i++;
		ptr = ptr->line_right;
	}
	data->x_colunms = i + 1;
	ft_printf("colunms= %d\t", data->x_colunms);
	ptr = lst;
	while (ptr)
	{
		if (ptr->y_map == (j + 1))
			j++;
		ptr = ptr->next;
	}
	data->y_row = j + 1;
	ft_printf("rows= %d\n", data->y_row);
}
