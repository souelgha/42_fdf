/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:52:23 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/11 12:11:36 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*m;

	m = str;
	while (n > 0)
	{
		m[n - 1] = '\0';
		n--;
	}
}
/*
#include<stdio.h>
#include<strings.h>
#include<string.h>

int main()
{
    int i;
	char tab1[100];
	memset(tab1, 'A', 100);
	
	i = 0;
	tab1[0] = 0;
    ft_bzero(tab1, 42);
	while( i < 100 && tab1[i] == 0)
		++i;
	printf("i =%d \n", i);		
    printf("so=%c \n", tab1[42]);
    return (0);
}*/