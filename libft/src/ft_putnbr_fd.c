/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:11:50 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/12 18:20:21 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			tab[20];
	int				i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		tab[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	tab[i] = nb % 10 + '0';
	while (i >= 0)
		ft_putchar_fd(tab[i--], fd);
}
/*
#include <limits.h>
int	main(void)
{
	char *file = "toto.txt";
	int	fd;
	int	n = -2147483648;
	fd = open(file, O_RDWR);
	ft_putnbr_fd(n, fd);
	close(fd);
	return (0);
}*/
