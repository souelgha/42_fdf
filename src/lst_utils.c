/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:20:58 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/16 15:20:02 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/*********free la list *************/
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

void	get_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	affiche_list(t_pix *map)
{
	t_pix	*ptr;

	ptr = map;
	while (ptr)
	{
		ft_printf("ptr<%p>\tx_map(%d)\ty_map(%d)\tz_map(%d)\tcol(%d)\t"
			"x_p(%d)\ty_p(%d)\tx_ad(%d)\ty_ad(%d)\t\nnext<%p>\t"
			"down<%p>\tright<%p>\n",
			ptr, ptr->x_map, ptr->y_map, ptr->z_map, ptr->color,
			ptr->x_pix, ptr->y_pix, ptr->x_adjust, ptr->y_adjust,
			ptr->next, ptr->line_down, ptr->line_right);
		ptr = ptr->next;
	}
}
