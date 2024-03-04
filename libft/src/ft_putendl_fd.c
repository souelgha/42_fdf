/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:27:30 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/25 11:19:44 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
/*
int	main(void)
{
	char *file = "toto.txt";
	char s[] = "hello world";
	int	fd;
	fd = open(file, O_RDWR);
	ft_putendl_fd(s, fd);
	ft_putstr_fd("MIAOU", fd);
	close(fd);
	return (0);
}*/
