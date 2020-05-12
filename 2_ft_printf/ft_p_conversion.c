/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:47:35 by jhur              #+#    #+#             */
/*   Updated: 2020/05/12 15:48:04 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_conversion(va_list *ap, t_list info, const char *format)
{
	void	*ptr;
	int		d_len;

	ptr = va_arg(*ap, void *);
	if (ptr == NULL && info.precision == 0)
		d_len = 3;
	else
		d_len = ft_len((long long)ptr) + 1;
	ft_left_blank(info.width, d_len, info.zero_flag, info.left);
	write(1, "0x", 2);
	if (info.precision == 0)
		ft_print_hex((long long)ptr, format);
	ft_right_blank(info.width, d_len, info.left);
	if (info.width > d_len)
		return (info.width);
	else
		return (d_len);
}
