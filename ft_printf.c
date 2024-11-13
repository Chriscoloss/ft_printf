/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:49:17 by chorst            #+#    #+#             */
/*   Updated: 2024/05/29 11:23:45 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_ret(int c)
{
	return (write(1, &c, 1));
}

int	ft_nbr_length(size_t n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		count++;
	}
	return (count);
}

int	format_specifiers(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_ret(va_arg(args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_printf_d_i(va_arg(args, int)));
	else if (c == 'x')
		return (ft_printf_x_low(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_printf_x_up(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (ft_printf_p(va_arg(args, size_t), c));
	else if (c == 's')
		return (ft_printf_s(va_arg(args, const char *)));
	else if (c == 'u')
		return (ft_printf_u(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar_ret('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	int		temp;
	va_list	args;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		temp = 0;
		if (str[i] == '%' && str[i + 1])
		{
			temp = format_specifiers(str[i + 1], args);
			i = i + 2;
		}
		else
			temp = ft_putchar_ret(str[i++]);
		if (temp == -1)
			return (-1);
		ret = ret + temp;
	}
	va_end(args);
	return (ret);
}
