/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdi_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:42:02 by jhur              #+#    #+#             */
/*   Updated: 2020/05/12 15:48:16 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_is_negative(t_list info, int d_len, int data)
{
	info.zero_flag = 0;
	data *= -1;
	d_len -= 1;
	if (info.p_len < d_len)
		ft_left_blank(info.width, d_len + 1, info.zero_flag, info.left);
	else
		ft_left_blank(info.width, info.p_len + 1, info.zero_flag, info.left);
	ft_putchar('-');
	ft_left_zero(info.p_len, d_len, 1, 0);
	ft_putnbr(data);
	if (info.p_len < d_len)
		ft_right_blank(info.width, d_len + 1, info.left);
	else
		ft_right_blank(info.width, info.p_len + 1, info.left);
	if (info.width > info.p_len && info.width > d_len)
		return (info.width);
	else
	{
		if (info.width < d_len && info.p_len < d_len)
			return (d_len + 1);
		else
			return (info.p_len + 1);
	}
}

int	d_is_positive(t_list info, int d_len, long long data)
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
		ft_putnbr(data);
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

int	d_without_precision_neg(t_list info, int d_len, long long data)
{
	data *= -1;
	ft_left_blank(info.width, d_len, info.zero_flag, info.left);
	write(1, "-", 1);
	ft_left_zero(info.width, d_len, info.zero_flag, info.left);
	ft_putnbr(data);
	ft_right_blank(info.width, d_len, info.left);
	if (info.width > d_len)
		return (info.width);
	else
		return (d_len);
}

int	d_without_precision(t_list info, int d_len, long long data)
{
	ft_left_blank(info.width, d_len, info.zero_flag, info.left);
	ft_left_zero(info.width, d_len, info.zero_flag, info.left);
	ft_putnbr(data);
	ft_right_blank(info.width, d_len, info.left);
	if (info.width > d_len)
		return (info.width);
	else
		return (d_len);
}

int	d_conversion(va_list *ap, t_list info)
{
	int	data;
	int	d_len;

	data = va_arg(*ap, int);
	d_len = ft_len((long long)data);
	if (data < 0)
	{
		if (info.precision == 1)
			return (d_is_negative(info, d_len, data));
		else
			return (d_without_precision_neg(info, d_len, data));
	}
	else
	{
		if (info.precision == 1)
			return (d_is_positive(info, d_len, data));
		else
			return (d_without_precision(info, d_len, data));
	}
}
