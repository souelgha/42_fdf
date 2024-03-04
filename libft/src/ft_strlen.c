/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:09:45 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/20 12:36:47 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
#include<stdio.h>
#include<string.h>

int main(void)
{
    printf("S=%lld \n", ft_strlen("tototototo"));
    printf("O=%lld \n", strlen("tototototo"));
    return (0);
}
*/
