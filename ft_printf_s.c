/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:39:38 by chorst            #+#    #+#             */
/*   Updated: 2024/03/26 15:23:43 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen_printf(const char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int	ft_printf_s(const char *str)
{
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	if (write (1, str, ft_strlen_printf(str)) == -1)
		return (-1);
	return (ft_strlen_printf(str));
}
