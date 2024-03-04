/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:21:37 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/12 15:46:18 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	char *file = "toto.txt";
	int	fd;
	fd = open(file, O_RDWR);
	printf("fd=%d",fd);
	ft_putchar_fd('2', fd);
	close(fd);
	return (0);
}*/
