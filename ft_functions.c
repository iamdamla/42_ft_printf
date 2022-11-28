/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:44:40 by derblang          #+#    #+#             */
/*   Updated: 2022/11/25 14:07:40 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	if (str < 0)
		return (-1);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_putint(int n)
{
	char	*str;
	int		i;

	str = ft_itoa(n);
	if (str == NULL)
		return (-1);
	i = ft_putstr(str);
	free(str);
	if (i < 0)
		return (-1);
	else
		return (i);
}
