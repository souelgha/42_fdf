/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:20:21 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/26 17:52:08 by sonouelg         ###   ########.fr       */
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
	if (fd == -1)
		return(1);
	printf("fd = %d\n", fd);
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
static unsigned long	ft_strtol(const char *str)
{
	const char		*hex;
	unsigned long	result;
	const char		*ptr;

	hex = "0123456789abcdef";
	result = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str != '\0')
	{
		ptr = ft_strchr(hex, *str);
		if (ptr == NULL)
			break ;
		result = result * 16 + (ptr - hex);
		str++;
	}
	return (result);
}