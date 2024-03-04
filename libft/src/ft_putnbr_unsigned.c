/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:03:59 by sonouelg          #+#    #+#             */
/*   Updated: 2023/12/02 11:54:15 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	char			tab[20];
	int				i;
	int				len;

	i = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nb != 0)
	{
		tab[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	len = i;
	i = i - 1;
	while (i >= 0)
		ft_putchar(tab[i--]);
	return (len);
}
/*
#include <limits.h>
int	main(void)
{
	unsigned int	n = 0;
	int len;
	
	len = ft_putnbr_unsigned(n);
	printf("\n len=%u", len);
	return (0);
}*/
