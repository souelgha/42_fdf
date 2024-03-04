/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:01:24 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/14 16:14:21 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count == 0 || size == 0)
		return ((void *)malloc(1));
	if (((count * size) / size) != count)
		return (NULL);
	str = malloc(count * size);
	if (str == NULL)
		return (str);
	ft_bzero(str, (count * size));
	return (str);
}
