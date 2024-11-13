/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:26:48 by chorst            #+#    #+#             */
/*   Updated: 2023/12/05 15:20:14 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(size_t n, char c)
{
	char	*base;

	base = "0123456789abcdef";
	if (c == 'p')
	{
		if (ft_putchar_ret('0') == -1)
			return (-1);
		if (ft_putchar_ret('x') == -1)
			return (-1);
		c = '\0';
	}
	if (n < 16)
	{
		if (ft_putchar_ret(base[n]) == -1)
			return (-1);
	}
	else
	{
		ft_printf_p(n / 16, c);
		if (ft_putchar_ret(base[n % 16]) == -1)
			return (-1);
	}
	return (2 + ft_nbr_length(n, 16));
}
