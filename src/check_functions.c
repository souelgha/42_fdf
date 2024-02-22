/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:43:24 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/22 17:56:58 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("invalide argument number", 1);
		return(0);
	}
	if (argc == 2 && ft_strncmp(".fdf", ft_strchr(argv[1], '.'), 4))
	{
		ft_putstr_fd("invalide file extension", 1);
		return(0);
	}
	return (1);
}