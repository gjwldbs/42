/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:40:08 by jhur              #+#    #+#             */
/*   Updated: 2020/05/06 16:40:35 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(int c)
{
	return ((c == '.') || (c == '*') || (c == '0') || (c == '-') || (c == ' '));
}

int	ft_isconversion(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'D')
	|| (c == 'i') || (c == 'C') || (c == 'S')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_conversion(int c, t_flags flags, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = c_conversion(va_arg(args, int), flags);
	else if (c == '%')
		count += percent_conversion(flags);
	else if (c == 'p')
		count = p_conversion(va_arg(args, unsigned long long), flags);
	else if (c == 's')
		count = s_conversion(va_arg(args, char *), flags);
	else if ((c == 'i') || (c == 'd'))
		count = d_conversion(va_arg(args, int), flags);
	else if (c == 'x')
		count += x_conversion(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += x_conversion(va_arg(args, unsigned int), 0, flags);
	else if (c == 'u')
		count += u_conversion((unsigned int)va_arg(args, unsigned int)
		, flags);
	return (count);
}
