/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:36:28 by derblang          #+#    #+#             */
/*   Updated: 2022/11/21 14:36:59 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_hex(unsigned int num, const char format);
int		ft_unsigned_int(unsigned int n);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
int		ft_putint(int n);
int		ft_pointer(unsigned long long ptr);

#endif
