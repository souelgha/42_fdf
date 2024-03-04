/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:32:03 by sonouelg          #+#    #+#             */
/*   Updated: 2023/12/02 11:53:59 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr ("cspdiuxX%", str[i + 1]))
		{
			len += ft_findformat(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int main(void)
{
	
	int i = printf(" %u  |", 9223372036854775807LL);
	printf("\ni=%d\n", i);
	int j = ft_printf(" %u  |", 9223372036854775807LL);
	printf("j=%d\n", j);

	return (0);	
}*/