/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:14:54 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/25 10:59:17 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_startsearch(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		count = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				count++;
			j++;
		}
		if (count >= 1)
			i++;
		else
			break ;
	}
	return (i);
}

static size_t	ft_endsearch(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		count = 0;
		while (set[j] != '\0')
		{
			if (s1[i] == set[j])
				count++;
			j++;
		}
		if (count >= 1)
			i--;
		else
			break ;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*restrim;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = ft_startsearch(s1, set);
	end = ft_endsearch(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	restrim = malloc((end - start + 1) * sizeof(char));
	if (restrim == NULL)
		return (NULL);
	i = 0;
	while (i < (end - start))
	{
		restrim[i] = s1[start + i];
		i++;
	}
	restrim[i] = '\0';
	return (restrim);
}
/*
int main(void)
{
	char const	*s1 = "   xxx   xxx";
	char const	*s2 = " x";
	char		*res;
	printf("%ld\n", ft_StartSearch(s1, s2));
    printf("%ld\n", ft_EndSearch(s1, s2));
	res = ft_strtrim(s1, s2);
	printf("%s\n", res);
	free(res);
	return (0);
}*/
