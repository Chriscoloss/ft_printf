/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:50:13 by chorst            #+#    #+#             */
/*   Updated: 2023/12/05 16:00:46 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(unsigned int b)
{
	if (b < 10)
	{
		if (ft_putchar_ret(b + '0') == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_u(b / 10) == -1)
			return (-1);
		if (ft_putchar_ret(b % 10 + '0') == -1)
			return (-1);
	}
	return (ft_nbr_length(b, 10));
}
