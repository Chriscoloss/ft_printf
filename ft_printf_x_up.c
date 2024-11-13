/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_X_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:05:32 by chorst            #+#    #+#             */
/*   Updated: 2023/12/05 16:30:02 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x_up(unsigned int n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n < 16)
	{
		if (ft_putchar_ret(base[n]) == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_x_up(n / 16) == -1)
			return (-1);
		if (ft_putchar_ret(base[n % 16]) == -1)
			return (-1);
	}
	return (ft_nbr_length(n, 16));
}
