/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:40:53 by derblang          #+#    #+#             */
/*   Updated: 2022/11/25 14:28:02 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf_checker(const char type, va_list args)
{
	if (type)
	{
		if (type == 's')
			return (ft_putstr(va_arg(args, char *)));
		else if (type == 'd' || type == 'i')
			return (ft_putint(va_arg(args, int)));
		else if (type == 'u')
			return (ft_unsigned_int(va_arg(args, unsigned int)));
		else if (type == 'x')
			return (ft_hex(va_arg(args, unsigned int), type));
		else if (type == 'X')
			return (ft_hex(va_arg(args, unsigned int), type));
		else if (type == 'p')
			return (ft_pointer(va_arg(args, unsigned long long)));
		else if (type == 'c')
			return (ft_putchar(va_arg(args, int)));
		else if (type == '%')
			return (ft_putchar('%'));
		else
			return (-1);
	}
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		count;

	count = 0;
	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = ft_printf_checker(str[i++ + 1], args);
		}
		else
			count = ft_putchar(str[i]);
		if (count < 0)
			return (-1);
		else
			len += count;
		i++;
	}
	va_end(args);
	return (len);
}
