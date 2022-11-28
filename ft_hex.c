/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:46:28 by derblang          #+#    #+#             */
/*   Updated: 2022/11/25 14:00:37 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_format_check(unsigned int num, const char format)
{	
	if (format == 'x')
	{
		if (ft_putchar((num - 10 + 'a')) < 0)
			return (-1);
	}
	if (format == 'X')
	{
		if (ft_putchar((num - 10 + 'A')) < 0)
			return (-1);
	}
	return (0);
}

int	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		if (ft_put_hex(num / 16, format) < 0)
			return (-1);
		if (ft_put_hex(num % 16, format) < 0)
			return (-1);
	}
	else
	{
		if (num <= 9)
		{
			if (ft_putchar((num + '0')) < 0)
				return (-1);
		}
		else
		{
			if (ft_format_check(num, format) < 0)
				return (-1);
		}
	}
	return (0);
}

int	ft_hex(unsigned int num, const char format)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	if (num == 0)
	{
		count += write(1, "0", 1);
		if (count < 0)
			return (-1);
		else
			len += count;
	}
	else
	{
		if (ft_put_hex(num, format) < 0)
			return (-1);
		count += ft_hex_len(num);
		if (count < 0)
			return (-1);
		else
			len += count;
	}
	return (len);
}
