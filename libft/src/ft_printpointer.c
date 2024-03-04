/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:33:42 by sonouelg          #+#    #+#             */
/*   Updated: 2023/12/02 13:55:55 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(void *p)
{
	unsigned long int	n;
	char				*base;
	char				tab[100];
	int					len;
	int					i;

	base = "0123456789abcdef";
	n = (unsigned long int)p;
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i = 0;
	while (n > 0)
	{
		tab[i++] = base[n % 16];
		n = n / 16;
	}
	len = i;
	while (--i >= 0)
		ft_putchar(tab[i]);
	return (len + 2);
}
