/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:17:24 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/12 10:52:24 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	lenght;

	lenght = ft_strlen(str);
	if (c == '\0')
		return ((char *)&str[lenght]);
	while (lenght > 0)
	{
		if (str[lenght - 1] == (char)c)
			return ((char *)(str + (lenght - 1)));
		else
			lenght--;
	}
	return (NULL);
}
/*
#include<stdio.h>
#include<string.h>

int main()
{
    char *res1;
    char *res2;
    res1 = ft_strrchr("hello world", 'e');
    res2 = strrchr("hello world", 'e');
  
    printf("or = %s \n", res2);   
    printf("so = %s\n", res1);
     
    return(0);
}*/
