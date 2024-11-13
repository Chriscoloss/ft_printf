/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:52:05 by chorst            #+#    #+#             */
/*   Updated: 2024/05/29 11:45:31 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_d_i(long long n)
{
	int	sign;

	sign = 0;
	if (n < 0)
	{
		if (ft_printf_s("-") == -1)
			return (-1);
		n = -n;
		sign++;
	}
	if (n < 10)
	{
		if (ft_putchar_ret(n + '0') == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_d_i(n / 10) == -1)
			return (-1);
		if (ft_putchar_ret(n % 10 + '0') == -1)
			return (-1);
	}
	return (ft_nbr_length(n, 10) + sign);
}

