/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:06:07 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/25 14:12:48 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			size_all;

	i = 0;
	j = 0;
	if ((!dest || !src) && size == 0)
		return (0);
	if (size <= ft_strlen(dest))
		return (ft_strlen(src) + size);
	size_all = ft_strlen(dest) + ft_strlen(src);
	while (dest[i] != '\0')
		i++;
	while ((src[j] != '\0') && (i < size - 1))
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (size_all);
}
/*
#include <bsd/string.h>
int	main(void)
{
//	char	dest[1] ;
//	char	dest2[1];
//	char 	desta[50];

//	dest[0] = 0;
//	dest2[0] = 0;
//	memset(dest, 0, 30);
//	memset(dest2, 0 ,30);
//	strcpy(desta, s1a);
	printf("or=%ld \n", strlcat("", "123", 0));
	printf("so=%ld \n", ft_strlcat("", "123", 0));
	return (0);
}*/
