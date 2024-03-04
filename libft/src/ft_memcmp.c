/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:44:20 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/14 12:55:07 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( const void *str1, const void *str2, size_t size)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = str1;
	s2 = str2;
	i = 0;
	while (i < size)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}
/*
int main() 
{
    int array1 [] = { -128, 85, 20, 63, 21 };
    int array2 [] = { 0, 85, 20, 63, 21 };
    size_t size = sizeof( int ) * 1;
//	char array1 [] = "hello wordd";
 //   char array2 [] = "hello world";
//    size_t size = sizeof( char ) * 15;

	printf("or=%d\n",memcmp( array1, array2, size));
	printf("so=%d\n",ft_memcmp( array1, array2, size));
	printf("or=%d\n",memcmp( array1, array1, size));
	printf("so=%d\n",ft_memcmp( array1, array1, size));
	printf("or=%d\n",memcmp( array2, array1, size));
    printf("so=%d\n", ft_memcmp( array2, array1, size));
}*/
