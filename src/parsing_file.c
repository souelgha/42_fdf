/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:20:21 by sonouelg          #+#    #+#             */
/*   Updated: 2024/02/23 17:22:45 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	pars_file(char *file, t_pix *pix, t_file *data)
{
    int		fd;
    int		i;
	int		j;
    char	*next_line;
	char 	**pixel;

	printf("%s\n", file);
	fd = open(file, O_RDONLY);
	printf("fd = %d\n", fd);
	i = 0;
	j = 0;
	next_line = get_next_line(fd);
	data->columns = 0;
	data->lines = 0;
	while (next_line)
	{
		pixel = ft_split(next_line, ' ');
		while (pixel[i])
		{
			printf("pix[%d]=%s\n", i, pixel[i]);
			onepix(pix, i, j, pixel[i]);
			i++;
		}
		free(next_line);
		free(pixel);
		next_line = get_next_line(fd);
		j++;
		data->columns += i;
		printf("col=%d\n", data->columns);
		i = 0;
	}
	data->lines = j;
	printf("lin=%d\n", data->lines);
	free(next_line);


    // while (next_line)
    // {
    //     printf("next_line[%d] = %s", i, next_line);
	// 	pixel = ft_split(next_line, ' ');
    //     free(next_line);
	// 	next_line = get_next_line(fd);
    //     i++;
    // }
	// printf("i=%d\n", i-1);
    return (0);
}
void	onepix(t_pix *pix, int	i, int j, char *pixel)
{
	char	**data;

	pix->posx = i;
	pix->posy = j;
	data = ft_split(pixel, ',');
	pix->height = ft_atoi(data[0]);
	printf("color=%s\n", data[1]);
	if(data[1])
		pix->color = data[1];
	else 
		pix->color = "0";
	free(pixel);
	free(data);
	printf("x(%d), y(%d), h(%d), c(%s)\n", pix->posx, pix->posy, pix->height, pix->color);
}
