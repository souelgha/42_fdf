/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:11:18 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/16 15:36:46 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char	*ft_readbuffer(int fd, char *str)
{
	char	*buf;
	int		read_bytes;

	read_bytes = 1;
	while (read_bytes > 0 && ((!str) || (!ft_strchr(str, '\n'))))
	{	
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		str = ft_strjoin(str, buf);
		free(buf);
	}
	return (str);
}

char	*ft_line(char *strread)
{
	int		i;
	char	*line;

	i = 0;
	if (strread[i] == 0)
		return (NULL);
	while (strread[i] != '\0' && strread[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (strread[i] != '\0' && strread[i] != '\n')
	{
		line[i] = strread[i];
		i++;
	}
	if (strread[i] == '\n')
	{
		line[i] = strread[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_nextline(char *strread)
{
	int		i;
	int		j;
	char	*nextline;

	i = 0;
	j = 0;
	if (strread[i] == '\0')
		return (NULL);
	while (strread[i] != '\0' && strread[i] != '\n')
		i++;
	nextline = malloc(sizeof(char) * (ft_strlen(strread) -i + 1));
	if (strread[i] == '\n')
		i++;
	if (nextline == NULL)
		return (NULL);
	while (strread[i] != '\0')
	{
		nextline[j] = strread[i];
		i++;
		j++;
	}
	nextline[j] = '\0';
	return (nextline);
}

char	*get_next_line(int fd)
{
	static char	*backup = NULL;
	char		*line;
	char		*buffer;

	if ((read(fd, 0, 0) < 0) || BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_readbuffer(fd, backup);
	if (buffer == 0)
		return (NULL);
	line = ft_line(buffer);
	backup = ft_nextline(buffer);
	free(buffer);
	return (line);
}
