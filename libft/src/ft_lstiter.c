/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:47:08 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/25 16:47:13 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*tmp;

	if (!lst || !f)
		return ;
	tmp = NULL;
	while (lst != NULL)
	{
		tmp = lst->next;
		(*f)(lst->content);
		lst = tmp;
	}
	lst = NULL;
}
