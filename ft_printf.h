/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chorst <chorst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:42:08 by chorst            #+#    #+#             */
/*   Updated: 2023/12/05 16:12:43 by chorst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int			ft_putchar_ret(int c);
int			ft_printf(const char *str, ...);
int			ft_printf_d_i(long long b);
int			ft_printf_x_low(unsigned int n);
int			ft_printf_x_up(unsigned int n);
int			ft_printf_p(size_t n, char c);
int			ft_printf_s(const char *str);
int			ft_printf_u(unsigned int b);
int			ft_nbr_length(size_t n, int base);

#endif
