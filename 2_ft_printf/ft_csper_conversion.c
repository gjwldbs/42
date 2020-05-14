/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csper_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:40:04 by jhur              #+#    #+#             */
/*   Updated: 2020/05/13 14:17:03 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		c_conversion(va_list *ap, t_list info)
{
	int		data;
	int		d_len;

	data = va_arg(*ap, int);
	d_len = 1;
	ft_left_blank(info.width, d_len, info.zero_flag, info.left);
	ft_putchar((char)data);
	ft_right_blank(info.width, d_len, info.left);
	if (info.width > 0)
		return (info.width);
	else
		return (1);
}

int		percent_conversion(t_list info)
{
	int		d_len;

	d_len = 1;
	ft_left_blank(info.width, d_len, info.zero_flag, info.left);
	ft_left_zero(info.width, d_len, info.zero_flag, info.left);
	ft_putchar('%');
	ft_right_blank(info.width, d_len, info.left);
	if (info.width > 0)
		return (info.width);
	else
		return (1);
}

void	s_with_precision(t_list info, int d_len, char *str)
{
	info.zero_flag = 0;
	if (info.p_len < 0)
	{
		if (info.p_len < d_len)
			ft_left_blank(info.width, d_len, info.zero_flag, info.left);
		ft_puts(str);
		if (info.p_len < d_len)
			ft_right_blank(info.width, d_len, info.left);
	}
	else
	{
		if (info.p_len < d_len)
			ft_left_blank(info.width, info.p_len, info.zero_flag, info.left);
		else
			ft_left_blank(info.width, d_len, info.zero_flag, info.left);
		ft_precision_puts(str, info.p_len);
		if (info.p_len < d_len)
			ft_right_blank(info.width, info.p_len, info.left);
		else
			ft_right_blank(info.width, d_len, info.left);
	}
}

void	s_without_precision(t_list info, int d_len, char *str)
{
	ft_left_blank(info.width, d_len, info.zero_flag, info.left);
	ft_puts(str);
	ft_right_blank(info.width, d_len, info.left);
}

int		s_conversion(va_list *ap, t_list info)
{
	char	*str;
	int		d_len;

	if (!(str = va_arg(*ap, char*)))
		str = "(null)";
	d_len = ft_strlen(str);
	if (info.precision == 1)
		s_with_precision(info, d_len, str);
	else
		s_without_precision(info, d_len, str);
	if (info.precision == 1)
	{
		if (info.p_len < d_len && info.p_len >= 0)
			d_len = info.p_len;
	}
	if (info.width > d_len)
		return (info.width);
	else
		return (d_len);
}
