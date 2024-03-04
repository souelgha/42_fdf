/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:45:00 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/11 13:24:04 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		i++;
	}
	return (dest);
}
/*
#include<stdio.h>
#include<string.h>
int main(void)
{      
    //char dest1[100];
    char src1[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    //char dest2[100];
    char src2[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    ft_memcpy(&src1[5], &src1[3], 5);
    memcpy(&src2[5], &src2[3], 5);
    printf("sonia = %s \n", src1);
    printf("origin = %s \n", src2);
   
    return (0);
}*/
