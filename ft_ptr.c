/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:48:59 by derblang          #+#    #+#             */
/*   Updated: 2022/11/25 14:06:40 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_ptrlen(uintptr_t num)
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

int	ft_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		if (ft_putptr(num / 16) < 0)
			return (-1);
		if (ft_putptr(num % 16) < 0)
			return (-1);
	}
	else
	{
		if (num <= 9)
		{
			if (ft_putchar(num + '0') < 0)
				return (-1);
		}
		else
		{
			if (ft_putchar(num - 10 + 'a') < 0)
				return (-1);
		}
	}
	return (0);
}

int	ft_pointer(unsigned long long ptr)
{
	int	len;
	int	count;

	len = 0;
	count = 0;
	count += write(1, "0x", 2);
	if (count < 0)
		return (-1);
	if (ptr == 0)
	{
		count += write(1, "0", 1);
		len += count;
	}
	else
	{
		if (ft_putptr(ptr) < 0)
			return (-1);
		count += ft_ptrlen(ptr);
		if (count < 0)
			return (-1);
		else
			len += count;
	}
	return (len);
}
