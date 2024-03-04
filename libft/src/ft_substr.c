/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:33:47 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/25 11:33:16 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if ((start >= (unsigned char)ft_strlen(s)) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	newstr = (char *) malloc((len + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < start)
		i++;
	while (s[i] != '\0' && i < (start + (unsigned int)len))
		newstr[j++] = ((char *)s)[i++];
	newstr[j] = '\0';
	return (newstr);
}
/*

#include <stdlib.h>
int main(void)
{
	const char *str = "Hello world_ bonjour tout le monde";
	char *newstr;
	unsigned int start = 5;
	size_t len = 10;

	newstr = ft_substr(str, start, len);
	printf("%s\n", newstr);
	printf("len=%ld\n", ft_strlen(str));
	free(newstr);
}*/
