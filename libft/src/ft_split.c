/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:23:37 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/25 11:32:08 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_findstr(char const *s, char c, size_t start)
{
	size_t	i;
	size_t	j;
	char	*segment;

	if (!s)
		return (NULL);
	i = 0;
	while (s[start + i] != c && s[start + i] != '\0')
		i++;
	segment = malloc((i + 1) * sizeof(char));
	if (segment == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		segment[j] = s[start + j];
		j++;
	}
	segment[j] = '\0';
	return (segment);
}

static size_t	ft_counttab(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
	{
		count = 0;
		return (count);
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i +1] == c || s[i +1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	k;
	size_t	count;

	count = ft_counttab(s, c);
	tab = (char **)malloc((count + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (k < count && s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0' && i < ft_strlen(s))
		{
			tab[k] = ft_findstr(s, c, i);
			i = i + ft_strlen(tab[k]);
			k++;
		}
		i++;
	}
	tab[k] = NULL;
	return (tab);
}
/*
int main(void)
{
//	const char *s = " tripouille";
	const char *s = "";
	char	**tab =  NULL;
	char	c = ' ';
	size_t	i = 0;
	size_t	count;

	count = ft_counttab(s, c);
	printf("count=%ld\n", count);		
	tab = ft_split(s, c);
	while ( i <= count)
	{
		printf("tab[%ld] =%s\n", i, tab[i]); 
		i++;
	}
	free(tab);
	return (0);
}*/
