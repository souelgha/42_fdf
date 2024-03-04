/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:19:23 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/11 12:11:31 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include<stdio.h>
#include<ctype.h>

int	main(void)
{
	printf("S=%d \n", ft_isalnum(10));
	printf("O=%d \n", isalnum(10));
	return (0);
}
*/
