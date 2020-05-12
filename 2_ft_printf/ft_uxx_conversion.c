/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uxx_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:43:43 by jhur              #+#    #+#             */
/*   Updated: 2020/05/12 15:59:54 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_conversion(va_list *ap, t_list info)
{
	unsigned int	data;
	int				d_len;

	data = va_arg(*ap, unsigned int);
	d_len = ft_len((long long)data);
	if (info.precision == 1)
		return (d_is_positive(info, d_len, data));
	else
		return (d_without_precision(info, d_len, data));
}

int	x_with_precision(t_list info, int d_len, long long data, const char *format)
{
	info.zero_flag = 0;
	if (info.p_len < d_len)
	{
		if (info.p_len == 0 && data == 0 && info.width != 0)
			write(1, " ", 1);
		ft_left_blank(info.width, d_len, info.zero_flag, info.left);
	}
	else
		ft_left_blank(info.width, info.p_len, info.zero_flag, info.left);
	ft_left_zero(info.p_len, d_len, 1, 0);
	if (info.p_len != 0 || data != 0)
		ft_print_hex(data, format);
	if (info.p_len < d_len)
		ft_right_blank(info.width, d_len, info.left);
	else
		ft_right_blank(info.width, info.p_len, info.left);
	if (info.p_len == 0 && data == 0 && info.width == 0)
		return (0);
	else if (d_len > info.p_len && d_len > info.width)
		return (d_len);
	else
	{
		if (info.p_len > info.width)
			return (info.p_len);
		else
			return (info.width);
	}
}

int	x_without_precision(t_list info, int d_len, long long data,
const char *format)
{
	ft_left_blank(info.width, d_len, info.zero_flag, info.left);
	ft_left_zero(info.width, d_len, info.zero_flag, info.left);
	ft_print_hex(data, format);
	ft_right_blank(info.width, d_len, info.left);
	if (info.width > d_len)
		return (info.width);
	else
		return (d_len);
}

int	x_conversion(va_list *ap, t_list info, const char *format)
{
	unsigned int	data;
	int				d_len;

	data = va_arg(*ap, int);
	d_len = ft_hex_len((long long)data);
	if (info.precision == 1)
		return (x_with_precision(info, d_len, data, format));
	else
		return (x_without_precision(info, d_len, data, format));
}
