/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:43:24 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/06 11:33:25 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("invalide argument number\n", 1);
		return(0);
	}
	if (argc == 2 && ft_strncmp(".fdf", ft_strchr(argv[1], '.'), 4))
	{
		ft_putstr_fd("invalide file extension\n", 1);
		return(0);
	}
	if (open(argv[1], O_RDONLY) == -1)
	{
		ft_putstr_fd("file doesn't exist\n", 1);
		return(0);
	}
		
	return (1);
}

/** nombre le lignes et colonnes dans le fichier.. a rechecker*/
void file_colums_rows(t_data *data, t_pix *lst) 
{
	t_pix *ptr;
	int 	i;
	int		j;
	
	ptr = lst;
	i = 0;
	j = 0;
	while (ptr->line_right != NULL)
	{
		i++;
	//	printf("i=%d\tptr<%p>\n", i, ptr);
		ptr = ptr->line_right;
	}
	data->x_colunms = i;
	printf("colunms= %d\t", data->x_colunms);
	ptr = lst;
	while (ptr)
	{
		if(ptr->y_map == (j + 1))
			j++;
		ptr = ptr->next;
	}
	data->y_row = j;
	printf("rows= %d\t\n", data->y_row);
}

void	img_centering(t_data *data)
{
	int delta;  //ecart entre 2 points en pixels.
	t_pix *current;

	current = data->node;
	if (data->x_colunms > data->y_row)
		delta = (IMGX * 0.5) / (data->x_colunms);
	else
		delta = (IMGY * 0.5) / (data-> y_row); 
	data->shift = delta;
	printf("shift= %d\n", data->shift);
	while (current)
	{
		current->x_pix = current->x_map * (delta);
		current->y_pix = current->y_map * (delta);
		current = current->next;
	}
	//data->delta = delta;

}