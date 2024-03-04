/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:33:12 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/11 12:13:22 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*m ;

	m = str;
	while (n > 0)
	{
		m[n - 1] = c;
		n--;
	}
	str = (void *)m;
	return (str);
}
/*
#include<stdio.h>
int main(void)
{
     int i;
	char tab1[100];
	memset(tab1, 'B', 100);
	
	i = 0;
	//tab1[0] = 0;
    ft_memset(tab1, 'A', 42);
	while( i < 100 )
	{
	//printf("i =%d \n", i);		
    printf("%c", tab1[i]);
	++i;
	}	
    return (0);
}*/
