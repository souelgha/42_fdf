/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonia <sonia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:20:21 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/01 13:51:42 by sonia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pars_file(char *file, t_pix **map) //argv[1] & list
{
    int		fd;
	int		i;
	int		j;
    char	*next_line;
	char 	**pixel;

	fd = open(file, O_RDONLY);
	i = 0;
	j = 0;
	next_line = get_next_line(fd);
	while (next_line)
	{
		pixel = ft_split(next_line, ' ');
		while (pixel[i])
		{
			initmap(map, i, j, pixel[i]);
			i++;
		}
		free(next_line);
		free(pixel);
		next_line = get_next_line(fd);
		j++;	
		i = 0;
	}
	free(next_line);
    return (0);
}
unsigned long	ft_atoi_hexa(const char *str)
{
	const char		*hex;
	unsigned long	result;
	const char		*ptr;
	int 			i;

	hex = "0123456789ABCDEF";
	result = 0;	
	if (!str)
		return (0);
	i = 2;
	while (str[i] != '\0' && str[i] != '\n')
	{
		ptr = ft_strchr(hex, str[i]);
		if (ptr == NULL)
			break ;
		result = result * 16 + (ptr - hex);
		i++;
	}
	return (result);
}
