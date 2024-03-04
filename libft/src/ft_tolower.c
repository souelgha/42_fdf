/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:56:05 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/11 12:13:50 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}
/*
#include<stdio.h>
#include<ctype.h>

int main(void)
{
    printf("S=%d \n", ft_tolower('Y'));
    printf("O=%d \n", tolower('Y'));
    return (0);
}*/
