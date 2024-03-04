/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:32:14 by sonouelg          #+#    #+#             */
/*   Updated: 2023/12/01 16:28:36 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_base(char c)
{
	char	*base_upper;
	char	*base_lower;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	if (c == 'x')
		return (base_lower);
	else
		return (base_upper);
}

int	ft_putnbr_hexa(unsigned long int n, char c)
{
	char	*base;
	char	tab[100];
	int		i;
	int		len;

	base = ft_base(c);
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		tab[i++] = base[n % 16];
		n = n / 16;
	}
	len = i;
	while (--i >= 0)
		ft_putchar(tab[i]);
	return (len);
}
/*
#include <limits.h>
int	main(void)
{
	unsigned long int	n = 0;
	int len;
	len = ft_putnbr_hexa(n, 'X');
	printf("\nlen=%d", len);
	return (0);
}*/
