/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:00:48 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/30 11:25:35 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	unsigned int	nb;
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int	sign_digit(int nbr)
{
	return (nbr < 0);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;

	str = malloc((count_digit(n) + sign_digit(n) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[n] = '0';
	if (sign_digit(n) == 1)
	{
		nb = -n;
		str[0] = '-';
	}
	else
		nb = n;
	i = 1;
	while (nb != 0)
	{		
		str[count_digit(n) + sign_digit(n) - i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}
	str[count_digit(n) + sign_digit(n)] = '\0';
	return (str);
}

#include<limits.h>	
int	main(void)
{
//	int	n = INT_MIN;
	int n = 14580;
	char *str;
	printf("count=%d\n", count_digit(n));
	printf("sign=%d\n", sign_digit(n));
	str = ft_itoa(n);
	printf("%s\n", str);
	free(str);
	return (0);
}
