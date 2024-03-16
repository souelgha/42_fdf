/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:16:03 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/16 12:27:54 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*********** inserer le node en fin de liste ******************/
void	ft_lstadd_back_s(t_pix **lst, t_pix *new_node)
{
	t_pix	*ptr;

	ptr = *lst;
	if (*lst == NULL)
	{
		*lst = new_node;
		new_node->next = NULL;
	}
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_node;
	}
}

/*********** parametres du node ****************************/
t_pix	*newpix(int i, int j, char *pixel)
{
	char	**data;
	t_pix	*new_node;

	new_node = malloc(sizeof(t_pix));
	if (new_node == NULL)
		return (NULL);
	new_node->x_map = i;
	new_node->y_map = j;
	data = ft_split(pixel, ',');
	new_node->z_map = ft_atoi(data[0]);
	new_node->color = ft_atoi_hexa(data[1]);
	new_node->x_pix = i;
	new_node->y_pix = j;
	new_node->x_adjust = 0;
	new_node->y_adjust = 0;
	new_node->line_down = NULL;
	new_node->line_right = NULL;
	new_node->next = NULL;
	get_free(data);
	return (new_node);
}

/***********init map *************************/
void	initmap(t_pix **map, int i, int j, char *pixi)
{
	t_pix	*newpx;

	newpx = newpix(i, j, pixi);
	ft_lstadd_back_s(map, newpx);
	free(pixi);
}
