/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x_low.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:40:06 by chorst            #+#    #+#             */
/*   Updated: 2023/12/05 16:28:47 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x_low(unsigned int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
	{
		if (ft_putchar_ret(base[n]) == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_x_low(n / 16) == -1)
			return (-1);
		if (ft_putchar_ret(base[n % 16]) == -1)
			return (-1);
	}
	return (ft_nbr_length(n, 16));
}
