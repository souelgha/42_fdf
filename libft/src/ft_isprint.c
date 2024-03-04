/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:44 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/11 12:13:14 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
#include<stdio.h>
#include<ctype.h>

int main(void)
{
    printf("S=%d \n", ft_isprint(127));
    printf("O=%d \n", isprint(127));
    return (0);
}
*/
