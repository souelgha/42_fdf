/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:16:19 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/18 12:20:15 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

/*
#include<stdio.h>
#include<string.h>
int main()
{
    char *res1;
    char *res2;
    res1 = ft_strchr("hello world", '\0');
    res2 = strchr("hello world", '\0');
  
    printf("origin = %s \n", res2);   
    printf("sonia = %s\n", res1);
     
    return(0);
}
*/
