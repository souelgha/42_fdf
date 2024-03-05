/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:20:58 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/05 14:23:31 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/** ******free la list *************/
void	ft_lstclear_s(t_pix **lst)
{
	t_pix	*tmp;

	if (!lst)
		return ;
	tmp = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
	}
	*lst = NULL;
}

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
void get_free(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
/***********imit map *************************/
void	initmap(t_pix **map, int i, int j, char *pixi)
{
	t_pix *newpx;

	newpx = newpix(i, j, pixi);
	ft_lstadd_back_s(map, newpx);
	free(pixi);
}

t_pix	*newpix(int	i, int j, char *pixel)
{
	char	**data;
	t_pix	*new_node;
	
	new_node = malloc(sizeof(t_pix));
	if (new_node == NULL)
		return (NULL);
	new_node->x_map = i;
	new_node->y_map = j;
	data = ft_split(pixel, ',');
	new_node->height = ft_atoi(data[0]);
	new_node->color = ft_atoi_hexa(data[1]);
	new_node->x_pix = i * 30;
	new_node->y_pix = j * 30;
	new_node->x_adjust = 0;
	new_node->y_adjust = 0;
	new_node->line_down = NULL;
	new_node->line_right = NULL;
	new_node->next = NULL;	
	get_free(data);
	return (new_node);	
}

void	affiche_list(t_pix *map)
{
	t_pix *ptr;

	ptr = map;
	while(ptr)
	{
		// printf("ptr<%p>\tx_map(%d)\ty_map(%d)\theight(%d)\t"
		// 	"color(%ld)\tx_p(%d)\ty_p(%d)\tnext<%p>\t"
		// 	"down<%p>\tright<%p>\n", 
		// 			ptr, ptr->x_map, ptr->y_map, ptr->height, 
		// 			ptr->color, ptr->x_pix, ptr->y_pix, ptr->next,
		// 			ptr->line_down, ptr->line_right);
		printf("ptr<%p>\tx_map(%d)\ty_map(%d)\t"
			"x_p(%d)\ty_p(%d)\tx_ad(%d)\ty_ad(%d)\tnext<%p>\t"
			"down<%p>\tright<%p>\n", 
					ptr, ptr->x_map, ptr->y_map, 
					ptr->x_pix, ptr->y_pix, ptr->x_adjust, ptr->y_adjust,
					ptr->next, ptr->line_down, ptr->line_right);
		ptr = ptr->next;
	}
}

void connect_right(t_pix *head)
{
	t_pix *ptr;

	ptr = head;
	while (ptr->next != NULL)
	{
		if (ptr->next->y_map == ptr->y_map)
			ptr->line_right = ptr->next;
		ptr = ptr->next;
	}
}
void connect_down(t_pix *head)
{
	t_pix *ptr;
	t_pix *current;

	current = head;
	while (current->next != NULL)
	{
		ptr = current->next;
		while (ptr != NULL)
		{
			if (ptr->x_map == current->x_map)
				current->line_down = ptr;
			ptr= ptr->next;
		}
		current = current->next;
	}
}