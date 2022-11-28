/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:37:46 by derblang          #+#    #+#             */
/*   Updated: 2022/11/21 14:40:35 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	if (len < 0)
		return (-1);
	else
		return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_num_len(n);
	if (len < 0)
		return (NULL);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_unsigned_int(unsigned int nb)
{
	int		len;
	char	*num;

	len = 0;
	if (nb < 0)
		return (-1);
	if (nb == 0)
	{
		len += write(1, "0", 1);
		if (len < 0)
			return (-1);
	}
	else
	{
		if (nb < 0)
			return (-1);
		num = ft_uitoa(nb);
		if (num == NULL)
			return (-1);
		len += ft_putstr(num);
		free(num);
		if (len < 0)
			return (-1);
	}
	return (len);
}
