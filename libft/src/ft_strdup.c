/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:08:01 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/12 10:47:44 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	size_src;
	int		i;

	size_src = ft_strlen(src);
	str = malloc((size_src + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		str[i] = ((char *)src)[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char    *str1 = strdup("Hello world");
	char	*str = ft_strdup("Hello world");
	printf("so=%s\n", str);
	printf("or=%s\n", str1);
	free(str);
	free(str1);
	return (0);
}*/
