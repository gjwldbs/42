/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhur <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:30:16 by jhur              #+#    #+#             */
/*   Updated: 2020/05/06 16:58:25 by jhur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			c_conversion(char c, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	count = ft_handle_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (count + 1);
}

static int	ft_input(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_handle_width(flags.dot, ft_strlen(str), 0);
		count += ft_putsp(str, flags.dot);
	}
	else
		count += ft_putsp(str, ft_strlen(str));
	return (count);
}

int			s_conversion(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_input(str, flags);
	if (flags.dot >= 0)
		count += ft_handle_width(flags.width, flags.dot, 0);
	else
		count += ft_handle_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += ft_input(str, flags);
	return (count);
}
