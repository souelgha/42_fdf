/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:29:50 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/11 15:11:59 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}
/*
#include<stdio.h>
int main(void)
{      
    //char dest1[100];
    char src1[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	char src2[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	    
    ft_memmove(&src1[4], &src1[2], 3);
    memmove(&src2[4], &src2[2], 3);
    printf("so = %s\n", src1);
    printf("or = %s\n", src2);
    return (0);
}*/
