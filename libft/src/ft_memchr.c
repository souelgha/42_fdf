/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:55:37 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/14 12:56:24 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int search, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((unsigned char *)str)[i] == (unsigned char)search)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
/*
int main()
{
    char *s1 = "012345";
    char *s2 = "012345";
	char *res1; 
	char *res2;
	int c = '0' + 256;
	size_t n = 3;
    res1 = ft_memchr(s1, c, n);
    res2 = memchr(s2, c, n);
  
    printf("or=%s\n", res2);   
    printf("so=%s\n", res1);
//
//	check(ft_memchr(s, 0, 0) == NULL); showLeaks();
//	* 2 */ //check(ft_memchr(s, 0, 1) == s); showLeaks();
	/* 3 */ //check(ft_memchr(s, 2, 3) == s + 2); showLeaks();
	/* 4 */ //check(ft_memchr(s, 6, 6) == NULL); showLeaks();
	/* 5 */ //check(ft_memchr(s, 2 + 256, 3) == s + 2); showLeaks() 
//    return(0);
//}//
