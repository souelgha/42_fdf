/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:11:00 by sonouelg          #+#    #+#             */
/*   Updated: 2024/03/16 15:36:14 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE _H 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30000
# endif

# include <unistd.h>
# include <stdlib.h>
# include "./libft.h"

// size_t	ft_strlen(const char *str);
// char	*ft_strdup(char *src);
// char	*ft_strjoin(char *s1, char *s2);
//char	*ft_strchr(const char *str, int c);
char	*ft_readbuffer(int fd, char *str);
char	*ft_line(char *stringread);
char	*get_next_line(int fd);

#endif