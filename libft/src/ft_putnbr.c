/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:33:21 by sonouelg          #+#    #+#             */
/*   Updated: 2023/12/02 12:34:29 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_findsign(int n)
{
	int	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	else
		sign = 0;
	return (sign);
}

int	ft_putnbr(int n)
{
	char			tab[20];
	int				i;
	unsigned int	nb;
	int				len;

	i = 0;
	len = ft_findsign(n);
	nb = n;
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	while (nb != 0)
	{
		tab[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	len += i;
	i = i - 1;
	while (i >= 0)
		ft_putchar(tab[i--]);
	return (len);
}
/*
#include <limits.h>
int	main(void)
{
	int	n = 27647;
	int len;
	
	len = ft_putnbr(n);
	printf("\n len=%d", len);
	return (0);
}*/
