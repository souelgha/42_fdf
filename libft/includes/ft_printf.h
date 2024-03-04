/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:30:46 by sonouelg          #+#    #+#             */
/*   Updated: 2024/01/30 14:38:53 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft.h"

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_printf(const char *format, ...);
int		ft_putnbr_hexa(unsigned long int n, char c);
int		ft_findformat(va_list args, const char format);
int		ft_printpointer(void *p);
int		ft_putnbr_unsigned(unsigned int n);

#endif
