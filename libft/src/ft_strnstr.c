/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:00:38 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/22 17:21:08 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t	i;
	size_t	j;

	if (small[0] == '\0')
		return ((char *)big);
	if (!big && n == 0)
		return (NULL);
	i = 0;
	while (big[i] != '\0' && i < n)
	{
		j = 0;
		if (big[i] == small[j])
		{
			while (big[i + j] == small[j] && small[j] != '\0' && (i + j) < n)
				j++;
			if (small[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
#include<stdio.h>
#include <bsd/string.h>
int main (void)
{
	size_t n = 2;
	char *res1;
	char *res2;

	res1 = strnstr( "aaabcabcd", "abcd", n);
	res2 = ft_strnstr("aaabcabcd", "abcd", n);
	
	printf("or=%s\n", res1);
	printf("so=%s\n", res2);

}*/
