/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:43:24 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/16 12:26:19 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("invalide argument number\n", 1);
		return (0);
	}
	if (argc == 2 && (!(ft_strchr(argv[1], '.'))))
	{
		ft_putstr_fd("invalide file name\n", 1);
		return (0);
	}
	if (argc == 2 && ((ft_strncmp(".fdf", ft_strrchr(argv[1], '.'), 4))))
	{
		ft_putstr_fd("invalide file extension\n", 1);
		return (0);
	}
	if (open(argv[1], O_RDONLY) == -1)
	{
		ft_putstr_fd("file doesn't exist\n", 1);
		return (0);
	}	
	return (1);
}
