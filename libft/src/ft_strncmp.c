/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:16:15 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/25 14:20:00 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		else
			i++;
	}
	return (0);
}
/*
#include<stdio.h>
#include<string.h>

int main()
{
    int res1;
    int res2;
    res1 = ft_strncmp("helo world", "hello wzrd", 9);
    res2 = strncmp("helo world", "hello wzrd", 9);
  
    printf("or = %d\n", res2);   
    printf("so = %d\n", res1);
     
    return(0);
}*/
