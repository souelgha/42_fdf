/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:57:34 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/12 10:46:38 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	length;	

	i = 0;
	length = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size -1))
		{	
			dest[i] = ((char *)src)[i];
			i++;
		}
		dest[i] = '\0';
	}
	length = ft_strlen(src);
	return (length);
}
/*
#include<bsd/string.h>

int	main()
{
	char	src[]= "Hello World";
	char	dest[100];

//	printf("so= %ld, dest= %s \n", ft_strlcpy(dest, src, 0), dest);
//	printf("or= %ld, dest= %s \n", strlcpy(dest, src,0), dest);

	printf("so= %ld, dest= %s \n", ft_strlcpy(dest, src, 5), dest);
	printf("or= %ld, dest= %s \n", strlcpy(dest, src, 5), dest);

//	printf("42_strlcpy= %d, dest= %s \n", ft_strlcpy(dest, src, 10), dest);
//  printf("strlcpy= %ld, dest= %s \n", strlcpy(dest, src, 10), dest);

	return (0);
}*/
