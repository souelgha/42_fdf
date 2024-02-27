/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colorscopy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:03:02 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/27 11:23:15 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	int		i;

	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}


unsigned long	ft_atoi_hexa(const char *str)
{
	const char		*hex;
	unsigned long	result;
	const char		*ptr;
	int 			i;

	hex = "0123456789ABCDEF";
	result = 0;
	
	if (str[0] == '0' && str[1] != 'x')
		return (0);
	i = 2;
	while (str[i] != '\0' && str[i] != '\n')
	{
		ptr = ft_strchr(hex, str[i]);
		if (ptr == NULL)
			break ;
		result = result * 16 + (ptr - hex);
		i++;
	}
	return (result);
}

int main()
{
	const char	*color = "0";
	unsigned long result = ft_atoi_hexa(color);
	printf("res = %ld", result);
	return (0);
}