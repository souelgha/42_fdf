/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:45:28 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/11 12:12:27 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include<stdio.h>
#include<ctype.h>

int main(void)
{
    printf("S=%d \n", ft_isascii(-250));
    printf("O=%d \n", isascii(-250));
    return (0);
}
*/
