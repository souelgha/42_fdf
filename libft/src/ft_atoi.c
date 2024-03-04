/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:03:17 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/23 14:40:59 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
/*
int main()
{	
	char str[] = "30";
	char *str2 = str;
	char *str1 = str;

	 int	nbr1 = 0;
	 int	nbr2 = 0;
	
	nbr1 = ft_atoi(str1);
	nbr2 = atoi(str2);
	printf("nbr1=%d\n", nbr1);
	printf("nbr2=%d\n", nbr2);
	return (0);

}*/
